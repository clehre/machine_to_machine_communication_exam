#ifndef _SNAKESTATE_H_
#define _SNAKESTATE_H_
#include "State.h"
#include "Snake.h"
#include "MatrixWebServices.h"
#define TIC 300

class SnakeState : public State
{
private:
    Snake *snake;
    Matrix *matrix;
    unsigned long prevTime;

public:
    void init();
    void mainloop();
    void cleanup();
    String id = "Snake";
    DIR takeInput(String inp);

    SnakeState(Matrix *matrix) : matrix(matrix)
    {
        init();
    };
    ~SnakeState(){};
};

#endif