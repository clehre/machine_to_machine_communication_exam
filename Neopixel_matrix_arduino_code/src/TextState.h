#ifndef _H_TEXTSTATE_
#define _H_TEXTSTATE_
#include "State.h"
#include "Matrix.h"
#include "MatrixWebServices.h"
class TextState : public State
{
private:
    Matrix *matrix;
    String displayText;

public:
    TextState(Matrix *matrix) : matrix(matrix)
    {
        init();
    };
    String id = "TextState";

    ~TextState(){};
    void setColor(String color);
    void mainloop();
    void cleanup();
    void init();
};

#endif