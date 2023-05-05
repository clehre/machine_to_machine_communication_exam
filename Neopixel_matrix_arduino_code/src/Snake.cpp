#include "Snake.h"

void Snake::grow()
{
    if (direction == LEFT)
        Snake::body.emplace_back(std::make_pair(body.back().first + 1, body.back().second));
    if (direction == RIGHT)
        Snake::body.emplace_back(std::make_pair(body.back().first - 1, body.back().second));
    if (direction == UP)
        Snake::body.emplace_back(std::make_pair(body.back().first, body.back().second + 1));
    if (direction == DOWN)
        Snake::body.emplace_back(std::make_pair(body.back().first, body.back().second - 1));
}
void Snake::move()
{
    for (int i = body.size() - 1; i > 0; i--)
    {
        body[i] = body[i - 1];
    }
    switch (direction)
    {
    case LEFT:
        if (body.front().first <= 0)
            body.front().first = WIDTH - 1;
        else
            body.front().first -= 1;
        break;
    case RIGHT:
        if (body.front().first >= 15)
            body.front().first = 0;
        else
            body.front().first += 1;

        break;
    case UP:
        if (body.front().second >= 15)
            body.front().second = 0;
        else
            body.front().second += 1;
        break;
    case DOWN:
        if (body.front().second < 0)
            body.front().second = HEIGHT - 1;
        else
            body.front().second -= 1;
        break;
    default:
        body.front().first += 1;
        break;
    }
}
void Snake::setDir(DIR dir)
{
    direction = dir;
}

void Snake::checkApple()
{
    if ((body.begin()->first == apple.first) && (body.begin()->second == apple.second))
    {
        grow();
        apple.first = random(1, 15);
        apple.second = random(1, 15);
    }
}
void Snake::draw()
{
    len = 0;
    r = 0;
    g = 255;
    b = 0;
    matrix->clear();

    for (auto &x : Snake::body)
    {
        matrix->drawPixel(x.first, x.second, Adafruit_NeoMatrix::Color(r, g, b));
        if ((x.first == body.front().first) && (x.second == body.front().second) && (&x != &body.front()))
        {
            Serial.println("dead");
            dead = true;
        }
        if (len <= 20)
        {
            g -= 10;
            b += 10;
            len++;
        }
    }
    matrix->drawPixel(apple.first, apple.second, Adafruit_NeoMatrix::Color(255, 0, 0));
    if (dead)
    {
        gameOver();
    }
    matrix->show();
}

void Snake::gameOver() // implement score?
{
    matrix->clear();
    body.clear();
    body.emplace_back(std::make_pair(x, y));
    body.emplace_back(std::make_pair(x - 1, y));
    body.emplace_back(std::make_pair(x - 2, y));
    body.emplace_back(std::make_pair(x - 3, y));
    apple = std::make_pair(random(1, 14), random(1, 14));
    dead = false;
}
