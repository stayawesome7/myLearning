#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int numChildren = 3;
    int childPids[numChildren];
    
    // Fork multiple child processes
    for (int i = 0; i < numChildren; i++) {
        childPids[i] = fork();
        
        if (childPids[i] == 0) { // Child process
            printf("Child %d (PID: %d) is running\n", i, getpid());
            sleep(1 + i); // Simulate work with sleep
            printf("Child %d (PID: %d) is exiting\n", i, getpid());
            exit(10 + i); // Exit with a unique status
        }
    }

    // Parent process waiting for all children to terminate
    for (int i = 0; i < numChildren; i++) {
        int status;
        pid_t pid = wait(&status); // Wait for any child to exit

        if (pid > 0) {
            if (WIFEXITED(status)) {
                printf("Parent: Child with PID %d exited with status %d\n", pid, WEXITSTATUS(status));
            } else {
                printf("Parent: Child with PID %d did not exit normally\n", pid);
            }
        }
    }

    printf("Parent: All children have exited. Parent exiting.\n");
    return 0;
}

