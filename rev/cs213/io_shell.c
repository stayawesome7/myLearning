#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    dup2(fd, STDOUT_FILENO);  // Redirect stdout to output.txt
    close(fd);  // Close original FD (not needed anymore)

    execlp("ls", "ls", NULL);  // Execute `ls`
    perror("execlp");
    return 1;
}

