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
//#include<stdlib.h>
int main()
{
	//mkfifo(pipePath, permission);
	int fd;
	char *pipePath;
	char buffer[200];

	pipePath = "/home/asibulhasanshanto/Desktop/class excercises/class5/1stPipe";	
	fd = open(pipePath, O_RDONLY);	
	read(fd,buffer,strlen(buffer));
	close(fd);

	write(STDOUT_FILENO, buffer,strlen(buffer) );

	return 0;
}
