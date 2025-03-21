#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1 = open("testfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd1 == -1) {
        perror("Error opening file");
        return 1;
    }

    int fd2 = dup(fd1);  // Duplicate fd1

    write(fd1, "Hello, ", 7);
    write(fd2, "World!\n", 7); // Uses fd2, but same file offset

    close(fd1);
    close(fd2);

    return 0;
}

