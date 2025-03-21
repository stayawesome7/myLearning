#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ALIGNMENT 512  // Disk block size
#define BUF_SIZE 512   // Must be a multiple of ALIGNMENT
#define FILE_NAME "direct_output.txt"

// Function to allocate aligned memory
void *aligned_alloc_memory(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, ALIGNMENT, size) != 0) {
        perror("posix_memalign failed");
        exit(1);
    }
    return ptr;
}

int main() {
    // Open file with O_DIRECT (bypassing kernel buffers)
    int fd = open(FILE_NAME, O_CREAT | O_WRONLY | O_DIRECT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Allocate an aligned buffer of BUF_SIZE (512 bytes)
    char *data = (char *)aligned_alloc_memory(BUF_SIZE);
    
    // Clear the buffer before using it
    memset(data, 0, BUF_SIZE);

    // Copy our message into the buffer
    strncpy(data, "Hello, No Kernel Buffering!", BUF_SIZE);

    // Write exactly BUF_SIZE (must match alignment requirements)
    ssize_t bytes_written = write(fd, data, BUF_SIZE);
    if (bytes_written == -1) {
        perror("Error writing to file");
    } else {
        printf("Wrote %zd bytes successfully.\n", bytes_written);
    }

    // Clean up
    free(data);
    close(fd);

    return 0;
}

