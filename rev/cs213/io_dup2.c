#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1 = open("testfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd1 == -1) {
        perror("Error opening file");
        return 1;
    }

    int fd2 = 5;  // Choose a specific FD
    dup2(fd1, fd2);  // Now fd2 refers to the same file as fd1

    write(fd2, "Using dup2\n", 11);

    close(fd1);
    close(fd2);

    return 0;
}

