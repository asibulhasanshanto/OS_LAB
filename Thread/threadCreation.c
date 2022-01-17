#include<stdio.h>
#include<pthread.h>

void sum(){
    int i;
    for(i = 0;i<50;i++){
        printf("Sub-thread\n");
    }
}
int main(){
    int i;
    pthread_t threadID;

    pthread_create(&threadID,NULL,(void *) sum,NULL);

    for(i=0;i<50;i++){
        printf("Main thread\n");
    }
    return 0;
}