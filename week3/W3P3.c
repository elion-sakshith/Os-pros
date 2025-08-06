#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("Child process (PID = %d) is exiting.\n", getpid());
        exit(0);  // Child exits
    } else {
        // Parent process
        printf("Parent process (PID = %d) is sleeping for 30 seconds.\n", getpid());
        sleep(30);  // Parent delays calling wait()
        printf("Parent is now exiting without wait().\n");
    }

    return 0;
}

