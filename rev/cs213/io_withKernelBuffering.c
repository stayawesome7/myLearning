#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("buffered_output.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char data[] = "Hello, Kernel Buffering!";
    write(fd, data, strlen(data));  // Data goes to kernel buffer first
    // No immediate write to disk; OS decides when to flush

    close(fd);  // OS may flush buffer to disk at close()
    
    return 0;
}

