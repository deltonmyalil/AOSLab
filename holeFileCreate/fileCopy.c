//Example 1
//Delton M Antony 18MCMI05 Mtech AI
/*
Write a program to create a file with free space 4kb free space. 
Such files are called files with holes
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h> // This removes the warning caused due to perror
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
char buf1[] = "LAB ";
char buf2[] = "OS Linux";


// This is how you create a hole in a file
// 1. Write something in the first pointer location returned by the creat/open function
// 2. Seek to another location
// 3. Write something in that locationd
int main() {
	int fd;
	// Highest permission given to files is 666
	// creat is a redundant function which is the same as calling open with the foll permissions
	// open(path, O_WRONLY|O_CREAT|O_TRUNC, mode)
	if((fd = creat("file.gol",0666))<0) {
		perror("Creation error"); // if creation fails, exit
		exit(1);
	}
	
	// write() is a function used to write data out of a buffer
	// in unistd.h
	// write in file, the string buf1. if it returns -ve, print error and exit
	if(write(fd,buf1,sizeof(buf1))<0){
		perror("Writing error");
		exit(2);
	}
	
	// lseek needs unistd.h and sys/types.h
	// lseek() is used to change the location of the system file pointer
	// we are now moving the file pointer to the 4096th byte of the file pointed by fp
	// SEEK_SET is an argument that says that the offset ie 4096 is to be measured in absolute terms
	// Other arguments are SEEK_CUR and SEEK_END ie seek from current location or backwards from end
	// If seeking fails, print error message
	if(lseek(fd,4096,SEEK_SET)<0){
		perror("Positioning error");
		exit(3);
	}
	
	// After 4096 bytes of empty spaces AKA hole, place some other string at the file pointer's location
	// if writing fails ie returns -ve, print error message
	if(write(fd,buf2,sizeof(buf2))<0){
		perror("Writing error");
		exit(2);
	}
}
