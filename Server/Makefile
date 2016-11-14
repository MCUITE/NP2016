all: server01 server02

server01: server01.o doprocessing.o
	gcc -o server01 server01.o doprocessing.o

server02: server02.o doprocessing.o
	gcc -o server02 server02.o doprocessing.o

clean:
	/bin/rm -rf server01 server02 *.o
