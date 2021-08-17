#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(){
	int pipeFD[2],status;
	pid_t childPID;

	//create a pipe, pipeFD[0]:read & pipeFD[1]:write 
	status = pipe(pipeFD);
	
	if(status == -1){
		printf("Error");
		exit(-1);
	}

	//create a child
	childPID = fork();
	if(childPID == -1){
		printf("Error");
		exit(-1);
	}
	else if(childPID == 0){//child
		printf("child process is writing to the pipe\n");
		printf("pipeRead:%d",pipeFD[0]);
		close(pipeFD[0]);
		char *msg = "hello\n";
		write(pipeFD[1],msg,strlen(msg)+1); 
	}
	else if(childPID > 0){//parent
		wait(NULL);
		printf("parent process is reading the pipe\n");
		close(pipeFD[1]);
		char buffer[200];
		read(pipeFD[0],buffer,sizeof(buffer));
		printf("%s\n",buffer);
	}

	printf("%d\n",status);
	return 0;
}
