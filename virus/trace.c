#include <stdlib.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <dlfcn.h>
#include <string.h>

int pt_main() {
    void *handle;
    long (*go)(enum __ptrace_request request, pid_t pid);

    // get a handle to the library that contains 'ptrace'
    handle = dlopen ("/lib/x86_64-linux-gnu/libc.so.6", RTLD_LAZY);

    // reference to the dynamically-resolved function 'ptrace'
    go = dlsym(handle, "ptrace");

    if (go(PTRACE_TRACEME, 0) < 0) {
        puts("being traced");
	exit(1);
    }

    puts("not being traced");

    // cleanup
    dlclose(handle);

    return 0;
}
