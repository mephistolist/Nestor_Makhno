#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <time.h>

void foo() {
    int i = 0;
    i++;
    long long q = (long long) i;
    char str[sizeof(long long)];
    sprintf(str, "%lld", q);

    FILE* fout = fopen("/dev/null", "w");
    fprintf(fout, str);
    fclose(fout);

    //printf("Random: %llx\n", q);
}

int change_page_permissions_of_address(void *addr) {
    // Move the pointer to the page boundary
    int page_size = getpagesize();
    addr -= (unsigned long)addr % page_size;

    if(mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return(-1);
    }

    return(0);
}

int mutate() {
    void *foo_addr = (void*)foo;

    srand(time(NULL));
    long long r = (long long)rand() * rand() * rand() / rand() * rand() + rand() + rand() - rand(); 

    // Change the permissions of the page that contains foo() to read, write, and execute
    // This assumes that foo() is fully contained by a single page
    if(change_page_permissions_of_address(foo_addr) == -1) {
        fprintf(stderr, "Error while changing page permissions of foo(): %s\n", strerror(errno));
        //return(1);
	exit(1);
    }

    /* Call the unmodified foo()
    puts("Calling foo...");
    foo();*/

    // Change the immediate value in the addl instruction in foo() to random hex number.
    unsigned char *instruction = (unsigned char*)foo_addr + 18;
    *instruction = r;

    /* Call the modified foo()
    puts("Calling foo...");*/
    foo();

    return(0);
}
