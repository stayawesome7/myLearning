#include <stdio.h>

void copyString(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Null terminator
}

int main() {
    char str1[] = "Pointer";
    char str2[20];

    copyString(str2, str1);
    printf("%s\n", str2);  // Output: Pointer

    return 0;
}

