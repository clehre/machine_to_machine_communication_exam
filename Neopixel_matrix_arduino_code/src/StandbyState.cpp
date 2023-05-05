
#include <StandbyState.h>
void StandbyState::mainloop()
{

    // maybe scrnsaver?
    currentTime = DateTime.getParts().getHours();
    if (currentTime >= morningStart && currentTime <= lunchStart)
        printText(morningText);
    else if (currentTime <= eveningStart)
        printText(eveningText);
    else if (currentTime <= happyHourStart)
        printText(happyHourText);
    else if (currentTime <= lateNightStart && (currentTime <= lateNightEnd && currentTime < 5))
        printText(lateEveningText);
    else
    {
        scrSaver();
    }
    if (Matrix::isDirty)
        parseText();
};
void StandbyState::printText(String text)
{
    matrix->clear();
    matrix->drawRGBBitmap(xStandbyCursor, 0, Scr_SVrTGIBG, TGIBGWIDTH, TGIBGHEIGHT);
    matrix->fillRect(0, 4, 16, 8, matrix->Color(255, 255, 255));
    matrix->setTextColor(matrix->Color(0, 0, 0));
    matrix->writeTextToMatrix(text);
    matrix->show();
    xStandbyCursor--;
    if (xStandbyCursor < -(TGIBGWIDTH - (WIDTH + 1)))
        xStandbyCursor = 0;
}
void StandbyState::scrSaver()
{
    matrix->clear();
    matrix->drawRGBBitmap(xStandbyCursor, 0, Scr_SVrTGIBG, TGIBGWIDTH, TGIBGHEIGHT);
    matrix->drawRGBBitmap(2, 4, Scr_SVrTGIFG, TGIFGWIDTH, TGIFGHEIGHT);

    matrix->show();
    xStandbyCursor--;
    if (xStandbyCursor < -(TGIBGWIDTH - (WIDTH + 1)))
        xStandbyCursor = 0;
    Serial.println("StandbyState");
}
void StandbyState::parseText()
{

    char delimiters[] = ";";
    char *data = MatrixWebServices::getTimeControlledString();
    Serial.println(data);

    const char *ptr = strtok(data, delimiters);
    if (ptr == NULL)
        return;
    morningText = ptr;
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;

    lunchText = ptr;
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;

    eveningText = ptr;
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;

    happyHourText = ptr;
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;
    lateEveningText = ptr;
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;
    morningStart = atoi(ptr);
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;

    lunchStart = atoi(ptr);
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;

    eveningStart = atoi(ptr);
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;

    happyHourStart = atoi(ptr);
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;

    lateNightStart = atoi(ptr);
    ptr = strtok(NULL, delimiters);
    if (ptr == NULL)
        return;

    lateNightEnd = atoi(ptr);
    // here i can add more if i want to parse time from the app in an extended version.
    Matrix::isDirty = false;
}
void StandbyState::cleanup(){};
void StandbyState::init(){};