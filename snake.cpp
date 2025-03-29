#include "snake.hpp"
#include <cassert>

Snake::Snake(int startX, int startY) {
    assert(startX >= 0 && startY >= 0); // Precondition: Valid starting position
    body.emplace_back(std::make_pair(startX, startY)); // Explicitly construct pair
    
}

const std::vector<std::pair<int, int> >& Snake::getBody() const {
    return body;
}

void Snake::move(Direction dir) {
    assert(!body.empty()); // Precondition: Snake must exist

    auto [headX, headY] = body.front(); // Get current head position

    switch (dir) {
        case Direction::UP:    headY--; break;
        case Direction::DOWN:  headY++; break;
        case Direction::LEFT:  headX--; break;
        case Direction::RIGHT: headX++; break;
    }

    body.insert(body.begin(), std::make_pair(headX, headY)); // Explicitly construct pair
    body.pop_back(); // Remove tail (constant size)
}
