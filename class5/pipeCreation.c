//permissions
//============
//		user	group	others
//r:100		  4	  4	  4
//w:010		  2	  2	  0
//x;001		  0	  0	  0
//		======================
//		0 6 	  6	  4

#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
//#include<stdlib.h>
int main()
{
	char *pipePath;
	pipePath = "/home/asibulhasanshanto/Desktop/class excercises/class5/2ndPipe";	
	mkfifo(pipePath, permission);


	return 0;
}
