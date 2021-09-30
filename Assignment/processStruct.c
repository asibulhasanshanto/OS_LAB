#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>

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

    child2 = fork();
    if(child2 == -1){
        printf("Can not create Reader Process\n");
        return 1;
    }
    else if(child2 == 0){
        //pipe reader
        printf("child2 %u, parent : %u\n",getpid(),getppid());
        for(int i = 0;i<1;i--){
            printf("child2 %u, parent : %u\n",getpid(),getppid());
        }

        return 0;
    }

    wait(NULL);
    wait(NULL);

    return 0;
}