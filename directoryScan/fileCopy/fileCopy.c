// 18MCMI05 Delton Myalil Antony Mtech AI

// Write a program to copy the contents of an existing file to another file.
// The names of the files should be read as an input from commandline
// Presume that write() and read() may cause errors

#include<sys/types.h>
#include<sys/uio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>  // to prevent warning from perror
#define BUFSIZE 512


// Accepts input and output fileNames from the command line.
// Copies the content of the input file to the output file
int main(int argc, char** argv) {  // input args, therefore run with ./fileCopy dummy.txt output.txt
	int from, to, nr, nw, n;
	char buf[BUFSIZE];
	
	// argv[0] is the input filename
	// open the input file in readOnly mode and init pf to 'from'
	// if open returns -ve, print error and exit
	if((from = open(argv[1], O_RDONLY))<0){
		perror("Opening error: src");
		exit(1);
	}
	
	
	// argv[2] is the output filename
	// create the output file with highest permission ie 0666 mode and init pf to 'to'
	// if open returns -ve, print error and exit
	if((to = creat(argv[2],0666))<0){
		perror("Opening error: dest");
		exit(2);
	}
	
	// read from 'from' to buf, if it fails, read() will return negative,
	// catch that and print error msg and exit
	// store that on buf
	while((nr = read(from, buf, sizeof(buf)))!=0){
		if(nr<0) {
			perror("Reading error: src");
			exit(3);
		}
		// the stored content on buf, along with the size stored in nr is used 
		// to write to the output file pointed by 'to'
		// (nr-nw) gives the size to be written
		// now write it to the output file whose filename is argv[1]
		// if write() returns negative, print error and exit
		nw = 0;
		do {
			if((n=write(to, &buf[nw],nr-nw))<0){
				perror("Writing error: dest");
				exit(4);
		}
		// n is the number of char (or size) read by read(), increment nw
		nw += n;
		} while (nw<nr); // do it till there is something to read ir nr is greater
	}
	// close both files
	close(from);
	close(to);
}