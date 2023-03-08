CC=gcc
CFLAGS=--std=c17 -pipe -D_GNU_SOURCE -s

all:
	$(CC) -c simple.c $(CFLAGS)
	$(CC) hello.c -o hello $(CFLAGS)
	$(CC) -c modify.c -Wall -Wextra $(CFLAGS)
	$(CC) -c path.c -O2 -march=native $(CFLAGS)
	$(CC) -c pids.c -Wall -Wextra -O2 -march=native $(CFLAGS)
	$(CC) -c trace.c -Wall -Wextra -O2 -march=native $(CFLAGS)
	$(CC) simple.o modify.o trace.o path.o pids.o -o Nestor_Makhno $(CFLAGS)
clean:
	rm -v Nestor_Makhno hello simple.o modify.o trace.o path.o pids.o
