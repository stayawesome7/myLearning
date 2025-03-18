#include <stdio.h>

int main() {

    // Stored in Stack
    char str1[] = "Hello";  // Implicit null character at the end
    char str2[5] = "World"; // Explicitly defining size
    char str3[] = {'H', 'i', '\0'}; // Manual null character inclusion
    // Store in RO
    char *str4 = "Hello, Pointer!"; // String literal assigned to pointer
				    // char *str points to a string literal stored in read-only memory.

    printf("%s %s %s\n", str1, str2, str3);
    return 0;
}

