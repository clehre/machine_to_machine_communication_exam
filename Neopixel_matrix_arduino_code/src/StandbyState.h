#ifndef _STANDBYSTATE_H
#define _STANDBYSTATE_H
#include <State.h>
#include <Arduino.h>
#include <Matrix.h>
#include <MatrixWebservices.h>
#include <ScreenSaver.h>
#include <DateTime.h>

class StandbyState : public State
{
private:
    Matrix *matrix;

    String morningText = "";
    String lunchText = "";
    String eveningText = "";
    String happyHourText = "";
    String lateEveningText = "";

    time_t currentTime;

    int xStandbyCursor = 0;

    int morningStart = 8;
    int lunchStart = 11;
    int eveningStart = 16;
    int happyHourStart = 22;
    int lateNightStart = 23;
    int lateNightEnd = 2;

public:
    void init();
    void cleanup();
    void mainloop();
    void scrSaver();
    void parseText();
    void printText(String text);
    String id = "StandBy";

    StandbyState(Matrix *ma)
    {
        init();
        matrix = ma;
    };
    ~StandbyState(){};
};
#endif