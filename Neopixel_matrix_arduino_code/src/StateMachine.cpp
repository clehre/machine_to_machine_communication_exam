#include <StateMachine.h>

void StateMachine::mainLoop()
{
    stateHolder->mainloop();
    webServices->mainLoop();

    matrix->show();
    inputChecker();
    Serial.println(stateHolder->id);

    delay(200);
};

void StateMachine::pushState(int mqttInput)
{

    // Maybe need to be implemented if cleaning states are needed
    if (oldState == mqttInput)
        return;
    switch (mqttInput)
    {
    case 0:
        stateHolder = standbyState;
        break;
    case 1:
        break;
    case 2:
        stateHolder = imageState;
        stateHolder->init();
        break;
    case 3:
        stateHolder = snakeState;
        stateHolder->init();

        break;
    case 4:
        stateHolder = textState;
        break;

    default:
        break;
    }
};
bool StateMachine::init()
{

    webServices = new MatrixWebServices();

    matrix = new Matrix(16, 16, 10, NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG, NEO_GRB + NEO_KHZ800);
    matrix->setBrightness(15);
    standbyState = new StandbyState(matrix);
    imageState = new ImageState(matrix);
    textState = new TextState(matrix);
    snakeState = new SnakeState(matrix);
    // lightSensor init
    lightSensor = new Adafruit_LTR329();
    while (!lightSensor->begin())
    {
        Serial.println("LTR sensor! ERROR!");
        delay(399);
    }
    lightSensor->setGain(LTR3XX_GAIN_4);
    lightSensor->setIntegrationTime(LTR3XX_INTEGTIME_50);
    lightSensor->setMeasurementRate(LTR3XX_MEASRATE_50);
    oldState = 0;
    matrix->begin();
    stateHolder = standbyState;

    DateTime.setServer("no.pool.ntp.org");
    DateTime.setTimeZone("GMT+1");

    DateTime.begin(10000); // timeout of 10 sec
    if (!DateTime.isTimeValid())
    {
        Serial.println("Failed to get time from server.");
    }
    Serial.println(DateTime.getTime());

    Matrix::isDirty = true;
    return true;
}
void StateMachine::inputChecker()
{
    uint16_t visiblePlusIr, IR;

    if (lightSensor->newDataAvailable())
        if (lightSensor->readBothChannels(visiblePlusIr, IR))
        {
            matrix->setBrightness(map(visiblePlusIr, 0, 800 / MatrixWebServices::getBrightness(), 5, 75));
        };
    int mqttInput = webServices->readInputField();
    pushState(mqttInput);
    oldState = mqttInput;
    return;
}