
#ifndef MATRIX_H
#define MATRIX_H
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>

#define FRAMES_PER_SECOND 120
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define BRIGHTNESS 20
#define NUM_LEDS 256
#define DATA_PIN 10
#define WIDTH 16
#define HEIGHT 16

class Matrix : public Adafruit_NeoMatrix
{
private:
    int currentCursor = 16;
    uint16_t textWidth;
    uint16_t textHeight;

public:
    static bool isDirty;

    void writeTextToMatrix(String text);

    Matrix(int w, int h, uint8_t pin, uint8_t matrixT, neoPixelType ledType) : Adafruit_NeoMatrix(w, h, pin, matrixT, ledType)
    {
        isDirty = true;
        setTextWrap(false);
        setBrightness(BRIGHTNESS);
    }

    ~Matrix(){};
};

#endif