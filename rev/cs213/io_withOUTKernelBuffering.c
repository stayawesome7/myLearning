#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ALIGNMENT 512  // Block size for direct I/O
#define FILE_NAME "direct_output.txt"

void *aligned_alloc_memory(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, ALIGNMENT, size) != 0) {
        perror("posix_memalign failed");
        exit(1);
    }
    return ptr;
}

int main() {
    int fd = open(FILE_NAME, O_CREAT | O_WRONLY | O_DIRECT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *data = (char *)aligned_alloc_memory(ALIGNMENT); // Allocate aligned buffer
    strcpy(data, "Hello, No Kernel Buffering!");  // Ensure data fits within alignment

    write(fd, data, ALIGNMENT);  // Directly writes to disk, bypassing kernel cache

    free(data);  // Free allocated buffer
    close(fd);

    return 0;
}

