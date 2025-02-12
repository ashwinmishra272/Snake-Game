#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include <optional>
#include <cassert>
#include <random>  // For random number generation

enum class Direction { Up, Down, Left, Right };

struct Position {
    int x, y;
    bool operator==(const Position& other) const { return x == other.x && y == other.y; }
};

class GameState {
private:
    int width, height;
    std::vector<Position> snake;
    std::optional<Position> food;
    Direction currentDirection;
    std::mt19937 rng;  // Random number generator

    static Position move(Position pos, Direction dir);
    void generate_food();  // New function to place food

public:
    GameState(int w, int h);
    
    int get_width() const;
    int get_height() const;
    const std::vector<Position>& get_snake() const;
    std::optional<Position> get_food() const;

    void move_snake(Direction dir);
    void print_board() const;
};

#endif // GAME_STATE_H