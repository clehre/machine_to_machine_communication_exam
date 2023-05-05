#ifndef _H_IMAGESTATE_
#define _H_IMAGESTATE_
#include "State.h"
#include "Matrix.h"
#include "MatrixWebServices.h"

typedef struct
{
    int x;
    int y;
    u_int16_t color;
} pixel;
class ImageState : public State
{
private:
    Matrix *matrix;
    pixel currentImage[300];
    int xCursor = 16;
    int yCursor = 0;
    int scrolling = 0;

public:
    String id = "ImageState";

    void getSplitViewImage();
    void mainloop();
    void cleanup();
    void init();

    ImageState(Matrix *matrix) : matrix(matrix)
    {
        init();
    };
    ~ImageState(){};
};
#endif
