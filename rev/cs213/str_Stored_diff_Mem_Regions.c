#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

// .bss section (Uninitialized global variable)
char bss_string[100]; 

// .data section (Initialized global variable)
char data_string[] = "Stored in .data section";  

int main() {
    // Stack (Local Variable)
    char stack_string[] = "Stored in Stack";  

    // Heap (Dynamically Allocated)
    char *heap_string = (char*)malloc(20 * sizeof(char));
    if (heap_string == NULL) {
        perror("malloc failed");
        return 1;
    }
    strcpy(heap_string, "Stored in Heap");

    // .bss section (Since it was uninitialized, we now assign a value)
    strcpy(bss_string, "Stored in .bss section");

    // Read-only .text section (String literal)
    char *text_string = "Stored in .text section";  

    // Memory-Mapped Region
    char *mmap_string = mmap(NULL, 4096, PROT_READ | PROT_WRITE, 
                             MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (mmap_string == MAP_FAILED) {
        perror("mmap failed");
        free(heap_string);
        return 1;
    }
    strcpy(mmap_string, "Stored in mmap region");

    // Printing values from different regions
    printf("Stack: %s (%p)\n", stack_string, (void*)stack_string);
    printf("Heap: %s (%p)\n", heap_string, (void*)heap_string);
    printf(".bss: %s (%p)\n", bss_string, (void*)bss_string);
    printf(".data: %s (%p)\n", data_string, (void*)data_string);
    printf(".text: %s (%p)\n", text_string, (void*)text_string);
    printf("mmap: %s (%p)\n", mmap_string, (void*)mmap_string);

    // Cleanup
    free(heap_string);
    munmap(mmap_string, 4096);

    return 0;
}

