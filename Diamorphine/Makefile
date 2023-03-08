obj-m := diamorphine.o
CC = gcc -Wall -O2 -march=native --std=c17 -pipe -s
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
