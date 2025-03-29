#include "snake.hpp"
#include <iostream>

int main() {
    Snake snake(5, 5);

    for (const auto& segment : snake.getBody()) {
        std::cout << "(" << segment.first << ", " << segment.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}