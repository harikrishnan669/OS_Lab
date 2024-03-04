#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;
    pid = fork();
    if (pid < 0) 
    {
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) 
    {
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID of the child: %d\n", getppid());
        sleep(2);
        exit(0);
    }
    else 
    {
        printf("Parent process ID: %d\n", getpid());
        printf("Child process ID of the parent: %d\n", pid);
        wait(&status);
        printf("Child process exited with status: %d\n", status);
    }

    return 0;
}