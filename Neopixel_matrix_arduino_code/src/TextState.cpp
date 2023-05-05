#include "TextState.h"

void TextState::cleanup() {}
void TextState::init()
{
    matrix->clear();
}
void TextState::mainloop()
{
    matrix->clear();
    String text = MatrixWebServices::getText();
    setColor(MatrixWebServices::getColor());
    matrix->writeTextToMatrix(text);
}

void TextState::setColor(String color)
{
    // doing this the easy way for a smaller string. Not with strtok as strtok needs char*
    int comma1 = color.indexOf(',');
    int r = color.substring(0, comma1).toInt();
    int comma2 = color.indexOf(',', comma1 + 1);
    int g = color.substring(comma1 + 1, comma2 + 1).toInt(); //
    int comma3 = color.indexOf(',', comma2 + 1);
    int b = color.substring(comma2 + 1, comma3 + 1).toInt();
    matrix->setTextColor(matrix->Color(r, g, b));
}