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

    int arr[5];
    int fd = open("sum",O_RDONLY);
    if(fd == -1){
        return 1;
    }

    for(int i = 0;i<5;i++){
        if(read(fd,&arr[i],sizeof(int))== -1){
            return 2;
        }
        printf("Recived %d\n",arr[i]);
    }
    close(fd);

    return 0;
}