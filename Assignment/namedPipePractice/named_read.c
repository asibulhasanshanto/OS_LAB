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

    for(int j = 0;j<5 ;j--){
        int arr[5];
        int fd = open("sum",O_RDONLY);
    if(fd == -1){
        printf("faild pointer \n");
    }

    for(int i = 0;i<5;i++){
        if(read(fd,&arr[i],sizeof(int))== -1){
            printf("faild read \n");
        }
        printf("Recived %d\n",arr[i]);
    }
    printf("\n"); 
    close(fd);

    }
    return 0;
}