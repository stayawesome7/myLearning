#include <stdio.h>
#include <unistd.h>
#include <termios.h>

void disable_buffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);      // Get current terminal attributes
    t.c_lflag &= ~ICANON;             // Disable canonical mode (line buffering)
//    t.c_lflag &= ~ECHO;               // Disable echo (optional)
    tcsetattr(STDIN_FILENO, TCSANOW, &t);  // Apply new settings
}

int main(void) {
    char c;
    disable_buffering(); // Disable terminal buffering

    while (read(0, &c, 1) != 0) {
        write(1, &c, 1);
    }
    return 0;
}

