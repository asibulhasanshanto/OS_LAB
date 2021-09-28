/*
Problem Description:
=====================

Create 3 child process.(2 child from the first child). sum an array partially using last 2 child process and send the result to their parent child process and add the sum and finally send the result to parent process and print them.


*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
// #include<time.h>

int main(){
    pid_t parent_process,child, child1_child,child2_child;

    child = fork();
    if(child == -1){
        printf("Could not create child process\n");
    }
    else if (child == 0){
        //first child of parent
        printf("from first child\n");
        printf("ID: %u\n",getpid());

        //creating a child of first child
        child1_child = fork();
        if(child1_child == -1){
            printf("Could not create child process 1 of first child\n");
        }
        else if(child1_child == 0){
            //child of first child
            printf("from a child of first child %u, parent: %u\n",getpid(),getppid());
        }
        else if(child1_child >0){
            //this is same as first child
            printf("ID: %u\n",getpid());
            fflush(stdout);
            
            //another child of first child
            child2_child = fork();

            if(child2_child == -1){
                printf("Could not create child process 2 of first child\n");
            }
            else if(child2_child == 0){
                //child of first child
                printf("from another child of first child %u, parent: %u\n",getpid(),getppid());
                // for(int i=0;i<1;i--){
                //     printf("infinite form %u\n",getpid());
                // }
            }
        }
    }
    else if(child>0){
        //parent process
        printf("from parent process:%u\n",getpid());
    }


    while(wait(NULL) != -1 || errno!= ECHILD){
        printf("waited for child from %u\n",getpid());
    } 
    return 0;
}