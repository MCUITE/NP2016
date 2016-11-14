all: server01 server02 thread

server01: server01.o doprocessing.o
	gcc -o server01 server01.o doprocessing.o

server02: server02.o doprocessing.o
	gcc -o server02 server02.o doprocessing.o


thread:	thread.o handler.o
	gcc -o thread thread.o handler.o -l pthread

clean:
	/bin/rm -rf server01 server02 handler *.o
