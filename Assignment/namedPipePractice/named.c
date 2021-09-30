#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>

int main(){

    //creating the named pipe
    if(mkfifo("sum",0777) == -1){
        if (errno!=EEXIST){
            printf("Could not create named pipe\n");
        }        
    }

    int pid = fork();
    int pid2 = fork();

    if(pid == 0){
        int arr[5]={1,9,5,7,4};
    int fd = open("sum",O_WRONLY);
    if(fd == -1){
        return 1;
    }
    for(int i = 0;i<5;i++){
        if(write(fd,&arr[i],sizeof(int))== -1){
            return 2;
        }
        printf("Wrote %d\n",arr[i]);
    }
    close(fd);
    }
    else {
        int arr[5]={0,0,0,0,0};
    int fd = open("sum",O_WRONLY);
    if(fd == -1){
        return 1;
    }
    for(int i = 0;i<5;i++){
        if(write(fd,&arr[i],sizeof(int))== -1){
            return 2;
        }
        printf("Wrote %d\n",arr[i]);
    }
    close(fd);
    }

    return 0;
}