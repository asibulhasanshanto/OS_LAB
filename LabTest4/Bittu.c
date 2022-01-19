#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){

        printf("From BITTU: %d\n",getppid());
    return 0;
}