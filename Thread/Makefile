all: thread1 thread2 thread3

thread1: thread1.o
	gcc -o thread1 thread1.o -lpthread

thread2: thread2.o 
	gcc -o thread2 thread2.o -lpthread


thread3:	thread3.o  handler.o
	gcc -o thread3 thread3.o handler.o -l pthread

clean:
	/bin/rm -rf thread1 thread2 thread3 *.o
