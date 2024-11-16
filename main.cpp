#include <iostream>

inline void printMessage() {
    std::cout << "Hello, World from inline function!" << std::endl;
}

int main() {
    printMessage();
    return 0;
}
