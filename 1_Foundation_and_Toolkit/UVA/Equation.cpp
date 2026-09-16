#include <iostream>

int main() {
    char ch;

    // Read character by character
    while (std::cin.get(ch)) {
        if (ch == '\n') {
            std::cout << "[Detected a newline character!]\n";
        }
        std::cout << "Read: " << ch << "\n";
    }
    return 0;
}
