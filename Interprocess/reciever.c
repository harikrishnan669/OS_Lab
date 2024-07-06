#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct area {
    int server_up;
    int client_up;
    int rw;
    char msg[100];
};

struct area *shmptr;

int main() {
    int shmid;
    shmid = shmget(700, sizeof(struct area), IPC_CREAT | 0666);
    shmptr = (struct area *)shmat(shmid, NULL, 0);

    while (1) {
        while (shmptr->rw != 1); 

        printf("get from user1: ");
        if(strcmp(shmptr->msg, "stop") == 0) {
            shmdt((void *)shmptr);
            shmctl(shmid, IPC_RMID, NULL);
            exit(0);
        }
        
        puts(shmptr->msg);
        
        printf("user2: ");
        fgets(shmptr->msg, 100, stdin);
        shmptr->msg[strcspn(shmptr->msg, "\n")] = '\0'; 
        
        if(strcmp(shmptr->msg, "stop") == 0) {
            shmptr->rw = 0; 
            shmdt((void *)shmptr);
            shmctl(shmid, IPC_RMID, NULL);
            exit(0);
        }
        
        shmptr->server_up = 0;
        shmptr->client_up = 1;
        shmptr->rw = 0; 
        
        while (shmptr->rw != 1);
    }

    shmdt((void *)shmptr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
