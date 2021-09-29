/*
Problem Description:
=====================

Create 3 child process.(2 child from the first child). sum an array partially using last 2 child process and send the result to main parent  process and add them and also  print them.


*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
// #include<time.h>

int calculate(int array[],int start,int end);

int main(){

    //main process started
    pid_t parent_process,child, child1_child,child2_child;
    int fd1[2],fd2[2];

    if(pipe(fd1)==-1 || pipe(fd2)==-1){
        printf("Can not create Pipe!!\n");
    }

    child = fork();
    if(child == -1){
        printf("Could not create child process\n");
    }
    else if (child == 0){
        //first child of parent
        printf("First child ID: %u\n",getpid());
        int arr[]={1,2,3,4,5};
        int arrSize = sizeof(arr)/sizeof(int);
        
        int start, end;
        int sum;


        //creating a child of first child
        child1_child = fork();
        if(child1_child == -1){
            printf("Could not create child process 1 of first child\n");
        }
        else if(child1_child == 0){
            //child of first child
            printf("C1_c: %u, P: %u\n",getpid(),getppid());
            start = 0;
            end = arrSize/2;
            

            //calculate result
            int sum1 = calculate(arr,start,end);
            
            //write to the first pipe
            close(fd1[0]);
            if(write(fd1[1] ,&sum1, sizeof(sum1)) == -1){
                printf("can not write sum1 to pipe1\n");
            }
            close(fd1[0]);
            
        }
        else if(child1_child >0){
            //this is same as first child
            
            
            //another child of first child
            child2_child = fork();

            if(child2_child == -1){
                printf("Could not create child process 2 of first child\n");
            }
            else if(child2_child == 0){
                //child of first child
                printf("C2_c: %u, P: %u\n",getpid(),getppid());
                start = arrSize/2;
                end = arrSize;

                //calculate result
                int sum2 = calculate(arr,start,end);

                //write to the second pipe
                close(fd2[0]);
                if(write(fd2[1],&sum2,sizeof(sum2)) == -1){
                    printf("can not write sum1 to pipe1\n");
                }
                close(fd2[0]);
                
            }
        }

    }
    else if(child>0){
        //parent process
        printf("from parent process:%u\n",getpid());

        //read from pipes
        int sum1,sum2;

        close(fd1[1]);
        if(read(fd1[0],&sum1,sizeof(sum1)) == -1){
            printf("can not read from first pipe\n");
        }
        close(fd1[0]);

        close(fd2[1]);
        if(read(fd2[0],&sum2,sizeof(sum2)) == -1){
            printf("can not read from first pipe\n");
        }
        close(fd2[0]);

        printf("first pipe result: %d\n",sum1);
        printf("second pipe result: %d\n",sum2);
        printf("total:%d\n",sum1+sum2);

    }


    while(wait(NULL) != -1 || errno!= ECHILD){
        printf("waited from: %u\n",getpid());
    } 
    return 0;
}

//calculate sum function
int calculate(int array[],int start,int end){
    int sum = 0;
    for(int i = start;i<end;i++){
        sum += array[i];
    }
    
    return sum;
}