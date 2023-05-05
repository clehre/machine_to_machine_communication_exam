#include "Matrix.h"
bool Matrix::isDirty = true;

void Matrix::writeTextToMatrix(String text)
{
    int16_t x1, y1;

    getTextBounds(text, 0, 0, &x1, &y1, &textWidth, &textHeight);

    Adafruit_NeoMatrix::setCursor(currentCursor, 4);
    Adafruit_NeoMatrix::print(text);

    if (currentCursor >= -textWidth)
    {
        --currentCursor;
    }
    else
    {
        currentCursor = 16;
    }
}
