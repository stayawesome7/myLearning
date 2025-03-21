#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
//dup2(fd1,fd2) now fd2 refers to the same file which fd1 refers also closes fd2 previous reference
    dup2(fd, STDOUT_FILENO);  // Redirect stdout to file 
    close(fd);  // No longer needed

    printf("This will be written to output.txt!\n");

    return 0;
}

