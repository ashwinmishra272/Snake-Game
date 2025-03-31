#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <utility>

enum class Direction { UP, DOWN, LEFT, RIGHT };

class Snake {
public:
    Snake(int startX, int startY);

    const std::vector<std::pair<int, int>>& getBody() const;
    
    void move(Direction dir);
    
private:
    std::vector<std::pair<int, int>> body;
    Direction currentDirection; // Store last move direction
    bool isOpposite(Direction newDir) const;
};

#endif // SNAKE_HPP