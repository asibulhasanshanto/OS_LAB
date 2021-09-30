#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
#include<signal.h>

int main(){
    pid_t child1,child2,childnofc2;

    //create first child of parent
    child1 = fork();
    if(child1 == -1){
        printf("Can not create Listener Process\n");
        return 1;
    }
    else if(child1 == 0){
        //pipe reader
        printf("child1 %u, parent : %u\n",getpid(),getppid());
        
        return 0;
    }


    //create second child process
    child2 = fork();
    if(child2 == -1){
        printf("Can not create Reader Process\n");
        return 1;
    }
    else if(child2 == 0){
        
        int n;
        printf("child2 %u, parent : %u\n",getpid(),getppid());
        
        for(int i = 0;i<10;i++){
            childnofc2 = fork();
            if(childnofc2 == -1){
                printf("Can not create child process: %u \t iteration: %d \n",childnofc2,i+1);
            }
            else if(childnofc2 == 0){
                
                printf("Child PID: %u \t parent PID: %u \t Child iteration: %d \n",getpid(),getppid(),i+1);
                               
                exit(0);
            }

            wait(NULL);
        
        } 


        return 0;
    }

    wait(NULL);
    wait(NULL);


    return 0;
}