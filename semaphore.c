#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
int sempahore=1;
int state=1;
void wait(int *sempahore)
{
    while(*sempahore<=0);
    *sempahore--;
}
void signal(int *sempahore)
{
    //sleep(1);
    *sempahore++;
}
void *thread_f(void *arg)
{
    int no=*((int*)arg);
    int st=no;
    while(1)
    {
        wait(&sempahore);
        if(state=st)
        {
            printf("Thread [%d]-> %d\n",st,no);
            no=no+2;
            state=3-st;
        }
        signal(&sempahore);
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t id1,id2;
    int odd=1;
    int even=2;
    pthread_create(&id1,NULL,(void *)thread_f,&odd);
    pthread_create(&id2,NULL,(void *)thread_f,&even);
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    return 0;
}
