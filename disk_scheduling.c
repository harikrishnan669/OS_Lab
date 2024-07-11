#include <stdio.h>
#include <stdlib.h>
int n,a[20],max,ini,total,i;
void fcfs()
{
        total=abs(ini-a[0]);
        for(i=0;i<n-1;i++)
        {
                total+=abs(a[i+1]-a[i]);
        }
        printf("FCFS total head movement(seek time)=%d\n",total);
}
void scan()
{
        int small=max;
        for(i=0;i<n;i++)
        {
                if(a[i]<small)
                {
                        small=a[i];
                }
        }
        total=abs(max-ini)+abs(max-small);
        printf("SCAN total head movement(seek time)=%d\n",total);
}
void cscan()
{
        int large=0;
        for(i=0;i<n;i++)
        {
                if(a[i]>large && a[i]<ini)
                {
                        large=a[i];
                }
        }
        total=abs(max-ini)+max+large;
        printf("CSCAN total head movement(seek time)=%d\n",total);
}
void main()
{
        printf("Enter the number of requests: ");
        scanf("%d",&n);
        printf("Enter the requests: ");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
        printf("Enter the total disc size: ");
        scanf("%d",&max);
        max--;
        printf("Enter the starting position: ");
        scanf("%d",&ini);
        fcfs();
        scan();
        cscan();
}
