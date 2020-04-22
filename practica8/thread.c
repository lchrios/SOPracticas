#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>

#define NUMTHREADS 10

int val = 5;
pthread_mutex_t mutex;

void * hello(void *id){
    printf("Hello, World!%d\n", (long)id, val);
    pthread_mutex_lock(&mutex);
    val += val;
    pthread_mutex_unlock(&mutex);
}
//Comment
int main(){
    pthread_t hilos[NUMTHREADS];
    pthread_mutex_init(&mutex,1);
    for (int i=0; i<10; i++){
        pthread_create(&hilos[i],NULL,hello,&i);
    }
    pthread_exit(NULL);
}
