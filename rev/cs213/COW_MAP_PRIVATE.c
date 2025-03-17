#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int *x = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (x == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    *x = 100; // Parent initializes x

    printf("Before fork - x address: %p, value: %d\n", x, *x);
    
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) { // Child process
        printf("Child before modifying x: address: %p, value: %d\n", x, *x);
        *x = 200; // Modify x (Triggers Copy-On-Write)
        printf("Child after modifying x: address: %p, value: %d\n", x, *x);
        exit(0);
    } else { // Parent process
        wait(NULL);
        printf("Parent after child modifies x: address: %p, value: %d\n", x, *x);
    }

    munmap(x, sizeof(int));
    return 0;
}

