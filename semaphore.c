#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int semaphore = 1;
int state = 1;
pthread_mutex_t lock;

void wait(int *semaphore) {
    while(*semaphore <= 0);
    (*semaphore)--;
}

void signal(int *semaphore) {
    (*semaphore)++;
}

void *thread_f(void *arg) {
    int no = *((int *)arg);
    int st = no;
    while(1) {
        pthread_mutex_lock(&lock);
        wait(&semaphore);
        if(state == st) {
            printf("Thread [%d]-> %d\n", st, no);
            no = no + 2;
            state = 3 - st;
        }
        signal(&semaphore);
        pthread_mutex_unlock(&lock);
        usleep(100000); 
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t id1, id2;
    int odd = 1;
    int even = 2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&id1, NULL, thread_f, (void *)&odd);
    pthread_create(&id2, NULL, thread_f, (void *)&even);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
