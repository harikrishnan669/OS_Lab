#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
pid_t pid = fork();
if(pid == 0)
{
execlp("./addnum.c", "addnum.c", NULL);
// Execute the add_numbers program
// If execlp returns, it means there was an error
perror("execlp");
}
else
{
wait(NULL);
}
}

Also create a sample program with the file name addnum.c

create a file name addnum.c

PROGRAM
#include<studio.h>
int main()
{
int num1,num2,sum;
printf("Enter the first number");
scanf("%d",&num1);
printf("Enter the second number");
scanf("%d",&num2);
sum=num1+num2;
printf("The sum is %d",sum);
}