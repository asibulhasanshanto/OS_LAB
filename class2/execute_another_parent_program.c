#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	pid_t status,pid;
	int *wstatus;

	status = fork();
	if(status==-1){
		printf("Could not create child process\n");	
	}
	else if(status == 0){//child process
		//printf("hello\n");
		execlp("/home/asibulhasanshanto/Desktop/class excercises/class2/child_process_code","child_process_code",NULL);	

	}
	else if(status >1){//parent process
		pid = getpid();
		printf("I am parent: %u\n",pid);	
		wait(wstatus);
		
		

	}
	
	return 0;
}
