#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 5

void *printHola(void *arg){
    printf("Hola desde un hilo\n");
    while(1){
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i],NULL,printHola,NULL);
    }

    pthread_exit(NULL);
    return 0;
}