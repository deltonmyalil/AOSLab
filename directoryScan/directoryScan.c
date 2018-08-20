// 18MCMI05 Delton M Antony
// WAP that displays the contents of a directory
// specifying the type of each of the files
// The name for the directory should be an input parameter

#include<sys/types.h> 
#include<sys/stat.h> 
#include<dirent.h> 
#include<stdio.h>
#include<stdlib.h>

//function to list directory content with arg as the directory name to analyze
void listDir(char *dirName) 
{
	DIR* dir; //pointer to dir
	struct dirent *dirEntry; //used for reading a directory 
	struct stat inode;
	char name[1000];

	//open directory
	dir = opendir(dirName);
	//if opendir returns 0, print error and exit
	if(dir == 0) 
	{
		perror("dir opening error");
		exit(1);
	}
	
	// Read dir content one by one and then print what it is
	while((dirEntry=readdir(dir)) != 0)
	{
		sprintf(name,"%s/%s",dirName,dirEntry->d_name);
		lstat(name, &inode);
		
		//test the file type
		if(S_ISDIR(inode.st_mode)) // directory
			printf("dir ");
		else if((S_ISREG(inode.st_mode))) // file
			printf("file ");
		else if((S_ISLNK(inode.st_mode))) // link
			printf("link ");
		else; // NOP
		printf(" %s\n", dirEntry->d_name); // print the name of the dir/file/link
	}
}

void main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("USE: %s name_dir\n", argv[0]);  // argv[0] is the input arg
		exit(0);
	}
	printf("The directory property is:");
	listDir(argv[1]);
}