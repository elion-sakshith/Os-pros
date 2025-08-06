#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(5);  // Wait so that parent exits first
        printf("Child after sleep: PID = %d, New PPID = %d (should be 1 or PID of 'init')\n", getpid(), getppid());
        exit(0);
    }
    else {
        // Parent process
        printf("Parent: PID = %d, exiting immediately.\n", getpid());
        exit(0);  // Parent exits before child
    }
}

