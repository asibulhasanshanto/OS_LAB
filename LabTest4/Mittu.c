#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    printf("From Mittu:%d\n",getppid());
    return 0;
}
