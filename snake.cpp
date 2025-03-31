#include "snake.hpp"
#include <cassert>

Snake::Snake(int startX, int startY) : currentDirection(Direction::RIGHT) {
    assert(startX >= 0 && startY >= 0); // Precondition: Valid starting position
    body.emplace_back(startX, startY);
}

const std::vector<std::pair<int, int>>& Snake::getBody() const {
    return body;
}

// Check if the new direction is opposite to current direction
bool Snake::isOpposite(Direction newDir) const {
    return (currentDirection == Direction::UP    && newDir == Direction::DOWN) ||
           (currentDirection == Direction::DOWN  && newDir == Direction::UP) ||
           (currentDirection == Direction::LEFT  && newDir == Direction::RIGHT) ||
           (currentDirection == Direction::RIGHT && newDir == Direction::LEFT);
}

void Snake::move(Direction dir) {
    assert(!body.empty()); // Precondition: Snake must exist

    // Prevent moving in the opposite direction
    if (isOpposite(dir)) return;

    auto [headX, headY] = body.front(); // Get current head position

    switch (dir) {
        case Direction::UP:    headY--; break;
        case Direction::DOWN:  headY++; break;
        case Direction::LEFT:  headX--; break;
        case Direction::RIGHT: headX++; break;
    }

    body.insert(body.begin(), {headX, headY}); // Add new head
    body.pop_back(); // Remove tail (constant size)
    
    currentDirection = dir; // Update last move direction
}