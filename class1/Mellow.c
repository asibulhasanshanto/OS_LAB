#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    pid_t mellow,killow,pillow;
    int i;
    mellow = fork();
    if(mellow<0){
        printf("failed\n");
exit(-1);
    }

    else if(mellow == 0){//child process
killow= fork();
    if(killow <0 ){//code for failing creating child process
        printf("unsuccessfull creating killow (:");
        exit(-1);  
    }
    else if(killow == 0){//for chld process
        for(i=0;i<1;i--){
            printf("I am child-:%u\n",getpid());
            //printf("killow:%u \t myParrent:%u\n",getpid(),getppid());
        }
    }
    else if (killow>0)//parnt process code{mellow}
    {
pillow = fork();
if(pillow <0 ){//code for failing creating child process
        printf("unsuccessfull creating pillow (:");
        exit(-1);  
    }
else if(pillow == 0){//for chld process
            for(i=0;i<1;i--){
printf("I am child-:%u\n",getpid());
                //printf("pillow:%u \t myParrent:%u\n",getpid(),getppid());
            }
    }
else if(pillow>0){//parent process{mellow}
    for(i=0;i<1;i--){
    printf("Process-%u,parent of Pillow%u and killow %u\n",getpid(),pillow,killow);
    }
}
    }
   
    }
    else if(mellow>0){
for(int i=0;i<1;i--){
printf("parent process:%u\n",getpid());
}
    }
   

    return 0;
}