#include "SnakeState.h"

void SnakeState::init()
{
    snake = new Snake(matrix);
    prevTime = millis();
    Serial.println("Snake init done");
}

void SnakeState::mainloop()
{
    snake->draw();
    snake->setDir(takeInput(MatrixWebServices::getSnakeDir()));
    if (millis() > prevTime + TIC)
    {
        snake->move();
        prevTime = millis();
    }

    snake->checkApple();
}
DIR SnakeState::takeInput(String input)
{
    if (input.equals("0") && snake->getDir() != DIR::DOWN)
        return DIR::UP;
    else if (input.equals("1") && snake->getDir() != DIR::UP)
        return DIR::DOWN;
    if (input.equals("2") && snake->getDir() != DIR::LEFT)
        return DIR::RIGHT;
    if (input.equals("3") && snake->getDir() != DIR::RIGHT)
        return DIR::LEFT;
    return DIR::CURRENT;
}
void SnakeState::cleanup()
{
    free(snake);
}