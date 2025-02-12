#include <iostream>
#include <algorithm>
#include "GameState.h"

GameState::GameState(int w, int h)
    : width(w), height(h), snake{{w / 2, h / 2}}, food(std::nullopt), currentDirection(Direction::Right), rng(std::random_device{}()) {
    assert(w > 0 && h > 0 && "Board dimensions must be positive");
    generate_food();  // Place the first food
}

// Move logic
Position GameState::move(Position pos, Direction dir) {
    switch (dir) {
        case Direction::Up:    return {pos.x, pos.y - 1};
        case Direction::Down:  return {pos.x, pos.y + 1};
        case Direction::Left:  return {pos.x - 1, pos.y};
        case Direction::Right: return {pos.x + 1, pos.y};
    }
    return pos;
}

// Function to generate food at a random position
void GameState::generate_food() {
    std::uniform_int_distribution<int> dist_x(0, width - 1);
    std::uniform_int_distribution<int> dist_y(0, height - 1);

    while (true) {
        Position newFood = {dist_x(rng), dist_y(rng)};
        
        // Ensure food does not spawn on the snake
        if (std::find(snake.begin(), snake.end(), newFood) == snake.end()) {
            food = newFood;
            return;
        }
    }
}

// Move the snake
void GameState::move_snake(Direction dir) {
    Position newHead = move(snake.front(), dir);

    // Check if out of bounds
    if (newHead.x < 0 || newHead.x >= width || newHead.y < 0 || newHead.y >= height) {
        std::cout << "Game Over! The snake hit the wall.\n";
        exit(0);
    }

    // Check for self-collision
    for (const auto& segment : snake) {
        if (newHead == segment) {
            std::cout << "Game Over! The snake hit itself.\n";
            exit(0);
        }
    }

    // Check if snake eats food
    if (food && newHead == food.value()) {
        snake.insert(snake.begin(), newHead); // Grow the snake
        generate_food(); // Generate new food
    } else {
        snake.insert(snake.begin(), newHead);
        snake.pop_back(); // Move normally
    }
}

// Getters
int GameState::get_width() const { return width; }
int GameState::get_height() const { return height; }
const std::vector<Position>& GameState::get_snake() const { return snake; }
std::optional<Position> GameState::get_food() const { return food; }

// Print board
void GameState::print_board() const {
    std::vector<std::vector<char>> board(height, std::vector<char>(width, '.'));

    for (size_t i = 0; i < snake.size(); ++i) {
        Position p = snake[i];
        board[p.y][p.x] = (i == 0) ? 'O' : 'o';
    }

    if (food) {
        board[food->y][food->x] = '*';
    }

    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << '\n';
    }
    std::cout << "-------------------\n";
}