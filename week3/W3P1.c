#include <stdio.h>      
#include <stdlib.h>    
#include <unistd.h>   
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Main process: PID = %d, PPID = %d\n", getpid(), getppid());

    pid = fork();  

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
        printf("Child sleeping for 5 seconds...\n");
        sleep(5);  // Simulate work
        printf("Child exiting now.\n");
        exit(0);   // Child terminates
    }
    else {
        // Parent process
        printf("Parent process: PID = %d, waiting for child (PID = %d)...\n", getpid(), pid);
        wait(NULL);  // Wait for child to finish
        printf("Parent: Child has finished.\n");
    }

    return 0;
}

