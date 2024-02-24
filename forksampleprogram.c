#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
int num,i,count=0;
printf("Enter the number: ");
scanf("%d",&num);
for(i=0;i<num; i++)
{
  fork();
}
printf("Heloo PID=%d\n",getpid());
return 0;
}
