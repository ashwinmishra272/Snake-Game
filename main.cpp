#include "snake.hpp"
#include <iostream>

void printSnake(const Snake& snake) {
    for (const auto& segment : snake.getBody()) {
        std::cout << "(" << segment.first << ", " << segment.second << ") ";
    }
    std::cout << std::endl;
}

int main() {
    Snake snake(5, 5);
    printSnake(snake);

    snake.move(Direction::RIGHT);
    printSnake(snake);

    snake.move(Direction::UP);
    printSnake(snake);

    return 0;
}