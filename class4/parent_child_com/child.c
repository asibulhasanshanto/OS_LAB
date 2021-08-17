#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){
        printf("%s:%s\n",argv[1],argv[2]);
        int result = atoi(argv[3]) + atoi(argv[4]);
        printf("child process is writing to the pipe\n");
		printf("pipeRead:%d",atoi(argv[1]));
		close(atoi(argv[1]));
		char *msg = "hello\n";
		write(atoi(argv[2]),msg,strlen(msg)+1); 
}