#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    pid_t pid;

    // Process 1 opens the file
    fd1 = open("testfile.txt", O_CREAT | O_RDWR, 0644);
    if (fd1 == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Fork a new process
    pid = fork();
    
    if (pid == -1) {
        perror("Fork failed");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        // Child process
	fd2 = open("testfile.txt", O_RDWR); // Child opens the file separately
        write(fd2, "Child", 5);
        printf("Child process wrote to file\n");
        close(fd2);
    } else {
        // Parent process
        sleep(1); // Ensure child writes first
        write(fd1, "Parent", 6);
        printf("Parent process wrote to file\n");
        close(fd1);
    }

    return 0;
}

