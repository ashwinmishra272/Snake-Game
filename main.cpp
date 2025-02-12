#include <iostream>
#include "GameState.h"

int main() {
    GameState game(30, 30);  // Create a 10x10 board

    char input;
    while (true) {
        game.print_board();

        std::cout << "Enter move (WASD): ";
        std::cin >> input;

        Direction dir;
        switch (input) {
            case 'w': dir = Direction::Up; break;
            case 's': dir = Direction::Down; break;
            case 'a': dir = Direction::Left; break;
            case 'd': dir = Direction::Right; break;
            default: continue;
        }

        game.move_snake(dir);
    }

    return 0;
}