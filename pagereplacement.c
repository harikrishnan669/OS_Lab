#include<stdio.h>
#include<stdlib.h>


int n,f,i,j,k,p,fault=0,flag;
void fifo(int[],int,int[],int);
void lru(int[],int,int[],int);
void lfu(int[],int,int[],int);

int main()
{
    printf("Enter the number of pages:");
    scanf("%d",&n);
    printf("Enter the number of frames:");
    scanf("%d",&f);
    int pages[n],realframes[f];
    printf("Enter the page Sequence\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    for(j=0;j<f;j++)
    {
        realframes[j]=-1;
    }
    lru(pages,n,realframes,f);
}


void printframe(int frames[],int f)
{
    int i;
    for(i=0;i<f;i++)
    {
        printf("%d",frames[i]);
    }
    printf("\n");
}

void lru(int pages[],int n,int realframes[],int f)
{
    int min;
    int frames[f],recent[f];
    for(j=0;j<f;j++)
    {
        frames[j]=realframes[j];  //coping real frames and recent to zero
        recent[j]=0;
    }
    fault=0;
    k=1;
    for(i=0;i<n;i++)   // page loop
    {
        p=pages[i];
        flag=1;
        for(j=0;j<f;j++)    // frame loop
        {
            if(p==realframes[j])  // hit/fault check
            {
                //hit occursss
                flag=0;
                recent[j]=k;
                k++;
                break;
            }
        }
        if(flag==1)
        {                  //fault occurs
            fault++;
            min=0;
            for(j=0;j<f;j++)   // finding minimum
            {
                if(recent[j]<recent[min])
                {
                    min=j;
                }
            }    
            frames[min]=p;   
            recent[min]=k;
            k++;
            printframe(frames,f);
        }
        else
        {
            printframe(frames,f);
        }
    }
    printf("Page Fault =%d",fault);
}

void lfu(int pages[],int n,int realframes[],int f)   
{
    int min;
    int frames[f],freq[f];    
    for(j=0;j<f;j++)
    {
        frames[j]=realframes[j];   // intialing freq with zero
        freq[j]=0;                 //frames=realframes
    }
    fault=0;
    for(i=0;i<n;i++)                //page loop
    {
        p=pages[i];
        flag=1;
        for(j=0;j<f;j++)                //frame loop
        {
            if(p==frames[j])       //hit/fault check;
            {
                flag=0;
                freq[j]++;
                break;
            }
        }
        if(flag==1)
        {
            fault++;
            min=0;
            for(j=0;j<f;j++)
            {
                if(freq[j]<freq[min])
                {
                    min=j;
                }
            }
            frames[min]=p;
            freq[min]=1;
            printframe(frames,f);
        }
        else
        {
            printframe(frames,f);
        }
    }
    printf("Page Fault=%d",fault);
}
