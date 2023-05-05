#include "ImageState.h"

void ImageState::mainloop()
{
    matrix->clear();
    scrolling = MatrixWebServices::getScrolling();
    if (Matrix::isDirty == true)
    {
        getSplitViewImage();
    }
    for (pixel p : currentImage)
    {
        matrix->drawPixel(p.x + xCursor, p.y + yCursor, p.color);
    }
    if (scrolling == 1)
    {
        if (xCursor < -16)
            xCursor = 16;
        xCursor--;
    }
    else
    {
        xCursor = 0;
    }
    matrix->show();
}

void ImageState::getSplitViewImage()
{

    int x = 0;
    int y = 0;
    char delimiters[] = ",";
    char *data = MatrixWebServices::getImg();
    const char *ptr = strtok(data, delimiters);
    int count = 0;
    int r, g, b;

    while (ptr != NULL && count < 270)
    {
        r = atoi(ptr);
        ptr = strtok(NULL, delimiters);
        g = atoi(ptr);
        ptr = strtok(NULL, delimiters);
        b = atoi(ptr);
        ptr = strtok(NULL, delimiters);
        if (x == 16)
        {
            x = 0;
            y++;
        }
        currentImage[count].color = matrix->Color(r, g, b);
        currentImage[count].x = x;
        currentImage[count].y = y;
        x++;
        count++;
    }

    Matrix::isDirty = false;
}
void ImageState::cleanup()
{
}
void ImageState::init()
{
    Matrix::isDirty = true;
}