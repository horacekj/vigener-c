all: main.c
	gcc -o vigener main.c

clean:
	rm -f vigener vigener.exe