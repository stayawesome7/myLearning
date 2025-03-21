#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;

    // Open the file
    fd1 = open("testfile.txt", O_CREAT | O_RDWR, 0644);
    if (fd1 == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Duplicate file descriptor
    fd2 = dup(fd1);

    // Write using both file descriptors
    write(fd1, "Hello ", 6);
    write(fd2, "World!", 6);

    printf("fd1 = %d, fd2 = %d\n", fd1, fd2);

    // Close the files
    close(fd1);
    close(fd2);

    return 0;
}

