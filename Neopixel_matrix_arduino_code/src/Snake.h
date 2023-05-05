#ifndef SNAKE_H
#define SNAKE_H
#include "DIR.h"
#include <vector>
#include "Matrix.h"
class Snake
{
private:
    int x;
    int y;
    int speed;
    int len = 0;
    int r, g, b;
    bool dead = false;

    DIR direction;

    std::vector<std::pair<int, int>> body;

    std::pair<int, int> apple;

    Matrix *matrix;

public:
    Snake(Matrix *matrix) : matrix(matrix), x(8), y(8), direction(RIGHT), speed(1), r(50), g(80), b(50)
    {
        body.emplace_back(std::make_pair(x, y));
        body.emplace_back(std::make_pair(x - 1, y));
        body.emplace_back(std::make_pair(x - 2, y));
        body.emplace_back(std::make_pair(x - 3, y));
        apple = std::make_pair(random(1, 14), random(1, 14));
    };
    DIR getDir() { return direction; }
    void setDir(DIR dir);
    void checkApple();
    void gameOver();
    void move();
    void grow();
    void draw();
};
#endif