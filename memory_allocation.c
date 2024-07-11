#include<stdio.h>
#include<stdlib.h>
struct block
{
    int size;
    int allocated;
}b[10],temp;
struct process
{
    int pid;
    int size;
    int blocksize;
}p[20];
int bn,pn,i,j;
void display()
{
    printf("\n");
    printf("PID  PROCESS_SIZE  BLOCKSIZE");
    printf("\n");
    for(i=0;i<pn;i++)
    {
       if(p[i].blocksize==-1)
       {
        printf("%d  %d  not allocated\n",p[i].pid,p[i].size);
       }
       else
       {
           printf("%d  %d  %d\n",p[i].pid,p[i].size,p[i].blocksize);
       }
    }
    printf("\n");
}
void firstfit()
{
    printf("\n FIRST FIT\n");
    for(i=0;i<bn;i++)
    {
        b[i].allocated=-1;
    }
    for(i=0;i<pn;i++)
    {
        p[i].blocksize=-1;
    }
    for(i=0;i<pn;i++)
    {
        for(j=0;j<bn;j++)
        {
            if(b[j].allocated==-1 && b[j].size>=p[j].size)
            {
                p[i].blocksize=b[j].size;
                b[j].allocated=1;
                break;
            }
        }
    }
    display();
}
void bestfit()
{
    printf("\n BEST FIT\n");
    for(i=0;i<bn-1;i++)
    {
        for(j=0;j<bn-i-1;j++)
        {
            if(b[j].size>b[j+1].size)
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    for(i=0;i<bn;i++)
    {
        b[i].allocated=-1;
    }
    for(i=0;i<pn;i++)
    {
        p[i].blocksize=-1;
    }
    for(i=0;i<pn;i++)
    {
        for(j=0;j<bn;j++)
        {
            if(b[j].allocated==-1 && b[j].size>=p[i].size)
            {
                p[i].blocksize=b[j].size;
                b[j].allocated=1;
            }
        }
    }
    display();
}
void worstfit()
{
    printf("\n WORST FIT\n");
    for(i=0;i<bn-1;i++)
    {
        for(j=0;j<bn-i-1;j++)
        {
            if(b[j].size<b[j+1].size)
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    for(i=0;i<bn;i++)
    {
        b[i].allocated=-1;
    }
    for(i=0;i<pn;i++)
    {
        p[i].blocksize=-1;
    }
    for(i=0;i<pn;i++)
    {
        for(j=0;j<bn;j++)
        {
            if(b[j].allocated==-1 && b[j].size>=p[i].size)
            {
                p[i].blocksize=b[j].size;
                b[j].allocated=1;
                break;
            }
        }
    }
    display();
}
void main()
{
    printf("Enter the number of blocks:");
    scanf("%d",&bn);
    for(i=0;i<bn;i++)
    {
        printf("Enter the size of block %d:",i+1);
        scanf("%d",&b[i].size);
    }
    printf("Enter the number of process:");
    scanf("%d",&pn);
    for(i=0;i<pn;i++)
    {
        printf("Enter the size of process %d:",i+1);
        scanf("%d",&p[i].size);
        p[i].pid=i+1;
    }
    firstfit();
    bestfit();
    worstfit();
}
