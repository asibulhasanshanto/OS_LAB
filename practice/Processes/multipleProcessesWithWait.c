

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>

int main  (){
    pid_t parent_id,child_1,child_2,child_3,child_4,child_pid;

    for(int i = 0;i<3;i++){
        child_pid = fork();
        if(child_pid == -1){
            printf("Can not create child process: %u \t iteration: %d \n",child_pid,i+1);
        }
        else if(child_pid == 0){
            
            printf("Child PID: %u \t parent PID: %u \t Child iteration: %d \n",getpid(),getppid(),i+1);
            
            exit(0);
        }
        else if(child_pid > 0){
            printf("From Parent : %u \t child pid: %u \t Parent iteration: %d \n",getpid(),child_pid,i+1);
        }
    }
    while(wait(NULL) != -1 || errno!= ECHILD){
        printf("waited for child from %u\n",getpid());
    } 
}
