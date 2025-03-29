#include "snake.hpp"
#include <cassert>

Snake::Snake(int startX, int startY) {
    assert(startX >= 0 && startY >= 0); // Precondition: Valid starting position
    body.push_back({startX, startY});
}

const std::vector<std::pair<int, int>> & Snake::getBody() const {
    return body;
}