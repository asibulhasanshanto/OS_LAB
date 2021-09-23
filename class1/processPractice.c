//create a child process and assign different tasks to different process
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    pid_t pid,cpid,cpid1,ppid1,parents_parent;
    int i;
    cpid= fork();
    if(cpid <0 ){//code for failing creating child process
        printf("unsuccessfull (:");
        exit(-1);
    }
    else if(cpid == 0){//for chld process
        //for(i=0;i<1;i--){
		cpid1 = getpid();
		ppid1 = getppid();
        	printf("Child1: %u\t",cpid1);        
		printf("parent1: %u\n \n",ppid1);//it'll show unexpected parent process id if the parent process doesent wait for the child process to finish.
	//}
    }
    else if (cpid>1)
    {
      // for(i = 0;i<1;i--){
	int *wstatus;
        pid = getpid();
	parents_parent = getppid();
        printf("parent1_c. %u \t child1_c: %u \t parant's parent id: %u\n",pid,cpid,parents_parent);
	wait(wstatus);
       	// }
    }
    

    return 0;
}
