//create a child process and assign different tasks to different process
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    pid_t pid,cpid,cpid1;
    int i;
    cpid= fork();//(returns negative /0/CHILD_PID)creates a child process. It'll start executing the child process from after the line in which fork is calld
    if(cpid <0 ){//code for failing creating child process
        printf("unsuccessfull (:");
        exit(-1);
    }
    else if(cpid == 0){//for chld process
        for(i=0;i<1;i--){
            cpid1 = getpid();
            printf("I am child process. %u\n",cpid1);
        }
    }
    else if (cpid>0)
    {
        //for(i = 0;i<1;i--){
	
	int *wstatus;
        pid = getpid();
        printf("i am parent process. %u, my child process: %u\n",pid,cpid);
	wait(wstatus);
        //}
    }
    

    return 0;
}
