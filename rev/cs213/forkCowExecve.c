#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int x = 100;  // Variable to test COW behavior

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process
        printf("Child: Before execve, x = %d at address %p\n", x, (void*)&x);
        
        // Prepare arguments for execve
        char *args[] = {"/bin/ls", "-l", NULL};  // Run "ls -l"
        
        // Execute new program, replacing the child process
        execve("/bin/ls", args, NULL);

        // If execve fails
        perror("execve failed");
        exit(1);
    } else {  // Parent process
        wait(NULL);  // Wait for the child to finish
        printf("Parent: After child exits, x = %d at address %p\n", x, (void*)&x);
    }

    return 0;
}

