#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    dup2(fd, STDIN_FILENO);  // Redirect stdin from input.txt
    close(fd);  // Close original FD

    execlp("wc", "wc", "-l", NULL);  // Execute `wc -l`
    perror("execlp");
    return 1;
}

