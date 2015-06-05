////////////////////////////////////////////////////////////////////////////////
// main.c: MAIN EXECUTABLE FILE TO THE VIGENER CIPHER PROGRAM
// Jan Horacek
// (C) Jan Horacek 2014
// jan.horacek@seznam.cz
// 22.05.2014
// v 1.1
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// implementation of vigener cipher
// this function accepts lowecase and uppercase words too, but returns only lowercase string
// returns 0 if ok, 1 if key validity fails, 2 if input validity fails
int vigener(unsigned char input[], unsigned char key[], unsigned char output[])
{
    unsigned int i, key_len;

    // make key lowercase
    for (key_len = 0; key[key_len]; key_len++)
    {
        key[key_len] = tolower(key[key_len]);

        // key validity control:
        if ((key[key_len] < 'a') || (key[key_len] > 'z')) return 1;
    }

    // apply vigener chiffree
    for (i = 0; input[i]; i++)
    {
        // make plaintext lowercase
        output[i] = tolower(input[i]);

        // validity control
        if ((output[i] < 'a') || (output[i] > 'z')) return 2;

        // move the character in alphabet
        output[i] = output[i]+(key[i%key_len]-'a');        

        // alphabet overflow control:
        if (output[i] > 'z') output[i] -= 26;
        if (output[i] < 'a') output[i] += 26;
    }
    output[i] = 0;

    return 0;
}

///////////////////////////////////////////////////////////

// main function
int main(int argc, char *argv[])
{
    int result;
    unsigned char input[100], output[100], key[100];

    // load plain text
    printf("Vigener cipher program:\nEnter plaintext:\n");
    scanf("%s", input);

    // load key
    printf("Enter a key:\n");
    scanf("%s", key);

    // execute vigener cipher and look at the result
    if ((result = vigener(input, key, output)) != 0)
    {
        if (result == 1)
            printf("Error %d: key is invalid (does not contain only characters)\n", result);
        if (result == 2)
            printf("Error %d: plain text is invalid (does not contain only characters)\n", result);
        return 1;
    }

    // print output
    printf("Output:\n%s\n", output);

    return 0;
}
