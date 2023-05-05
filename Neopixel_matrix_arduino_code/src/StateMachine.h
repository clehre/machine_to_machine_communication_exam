#ifndef _STATEMACHINE_H
#define _STATEMACHINE_H

#include <DateTime.h>

#include "State.h"
#include "Matrix.h"
#include "TextState.h"
#include "SnakeState.h"
#include "ImageState.h"
#include "StandbyState.h"
#include "MatrixWebServices.h"
#include "Adafruit_LTR329_LTR303.h"
class StateMachine
{
private:
    int oldState = 0;

    Matrix *matrix;

    State *stateHolder;

    TextState *textState;
    SnakeState *snakeState;
    ImageState *imageState;
    StandbyState *standbyState;
    Adafruit_LTR329 *lightSensor;
    MatrixWebServices *webServices;

public:
    bool init();
    void mainLoop();
    void inputChecker();
    void pushState(int oldState);

    StateMachine()
    {

        if (init())
            Serial.println("stateMachine initiated!");
    };
    ~StateMachine(){};
};
#endif