#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <utility>

class Snake {
public:
    Snake(int startX, int startY);

    const std::vector<std::pair<int, int>>& getBody() const;

private:
    std::vector<std::pair<int, int>> body;
};

#endif // SNAKE_HPP