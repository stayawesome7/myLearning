#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int x = 100;  // Variable shared due to COW

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process
        printf("Child: Before modification, x = %d at address %p\n", x, (void*)&x);
        x = 200;  // Modifying x in child should create a new copy (COW)
        printf("Child: After modification, x = %d at address %p\n", x, (void*)&x);
        exit(0);
    } else {  // Parent process
        wait(NULL);  // Wait for the child to finish
        printf("Parent: After child's modification, x = %d at address %p\n", x, (void*)&x);
    }

    return 0;
}

