#include<stdio.h>
#include<stdlib.h>
int n,f,i,j,k,fault=0,flag;
void printframes(int frames[],int f)
{
    int i;
    for(i=0;i<f;i++)
    {
       if(frames[i]==-1)
       {
            printf("_\t");
       }
       else{
       printf("%d\t",frames[i]);
       }
    }
    printf("\n");
}
void fifo(int pages[],int n,int realframes[],int f)
{
    int frames[f];
    for(j=0;j<f;j++)
    {
        frames[j]=realframes[j];
    }
    printf("FIFO\n");
    fault=0;
    k=0;
    for(i=0;i<n;i++)
    {
        int p;
        p=pages[i];
        flag=0; 
        for(j=0;j<f;j++)
        {
            if(p==frames[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            fault++;
            frames[k]=p;
            k=(k+1)%f;
            printframes(frames,f);
        }
        else
        {
            printframes(frames,f);
        }
    }
    printf("page fault=%d",fault);    
}

void main()
{
    
    printf("enter the no of pages");
    scanf("%d",&n);
    printf("enter the no of frames");
    scanf("%d",&f);
    int pages[n],realframes[f];
    printf("enter page squences");
    //printf("hiiii");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    for(j=0;j<f;j++)
    {
        realframes[j]=-1;
    }
    fifo(pages,n,realframes,f);


    
}
