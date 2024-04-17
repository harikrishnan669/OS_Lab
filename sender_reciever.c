// SHARED MEMORY ------>  SENDER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
struct share
{
    int server;
    int client;
    int flag;
    char chat[100];
};
struct share* shmptr1;
int main()
{
    int shmid;
    int key=500;
    shmid=shmget(key,sizeof(struct share),IPC_CREAT|0666);
    shmptr1=(struct share*)shmat(shmid,NULL,0);
    shmptr1->flag=0;
    while(1)
    {
        while(shmptr1->flag!=1);

            while(shmptr1->client==0)
            {
                printf("Recieved from reciever");
                if(strcmp(shmptr1->chat,"stop")==0)
                {
                    exit(1);
                }
                else
                {
                    puts(shmptr1->chat);
                }
                shmptr1->server=0;
                shmptr1->client=1;
            }
            printf("USER 2:");
            if(strcmp(shmptr1->chat,"stop")==0)
            {
                exit(1);
            }
            else
            {
                fgets(shmptr1->chat,100,stdin);
                shmptr1->chat[strcspn(shmptr1->chat,"\n")]='\0';
            }
            shmptr1->flag=0;
        }
        shmctl(shmid,IPC_RMID,NULL);
        return 0;
    }
// SHARED MEMORY ------> RECIEVER


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
struct share
{
    int server;
    int client;
    int flag;
    char chat[100];
};
struct share* shmptr1;
int main()
{
    int shmid;
    int key=500;
    shmid=shmget(key,sizeof(struct share),IPC_CREAT|0666);
    shmptr1=(struct share*)shmat(shmid,NULL,0);
    shmptr1->flag=0;
    while(1)
    {
        while(shmptr1->flag!=1);

            while(shmptr1->client==0)
            {
                printf("Recieved from sender");
                if(strcmp(shmptr1->chat,"stop")==0)
                {
                    exit(1);
                }
                else
                {
                    puts(shmptr1->chat);
                }
                shmptr1->server=1;
                shmptr1->client=0;
            }
            printf("USER 1:");
            if(strcmp(shmptr1->chat,"stop")==0)
            {
                exit(1);
            }
            else
            {
                fgets(shmptr1->chat,100,stdin);
                shmptr1->chat[strcspn(shmptr1->chat,"\n")]='\0';
            }
            shmptr1->flag=0;
        }
        shmctl(shmid,IPC_RMID,NULL);
        return 0;
    }

