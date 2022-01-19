#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>



int main(int argc, char *argv[]){
    int a,b;
    printf("From ITTU:%d\n",getppid());
    a = atoi(argv[1]);
    printf("%d\n",a);
    return 0;
}

