#include "MatrixWebServices.h"
// needed to workaround stupid c++14 rules global scope
char *image;
char *timeControlledText;

static int prevmenu = 0;

static String text = "";
static String snakeDir = "";
static String textColor = "";
static int brightness = 2;
static String textTopic = "d1/Text";
static String menuTopic = "d1/menu";
static String snakeTopic = "d1/snake";
static String aliveTopic = "d1/alive";
static String standbyTopic = "d1/sleep";
static String imageTopic = "d1/imageData";
static String brightnessTopic = "d1/brightness";
static String textColorTopic = "d1/TextColor";
static String isScrollingTopic = "d1/scrolling";
static String timeControlledTopic = "d1/timeControlled";
static int isScrolling = 1;
bool MatrixWebServices::mainLoop()
{
    mqtt->loop();

    if (millis() > prev_ms + UPDATETIMER)
    {
        prev_ms = millis();
        mqtt->publish(aliveTopic, "ALIVE_ESP!");
    }
    return true;
}
int MatrixWebServices::getBrightness()
{
    return brightness;
}
int MatrixWebServices::readInputField()
{
    return prevmenu;
}
char *MatrixWebServices::getImg()
{
    return image;
}
String MatrixWebServices::getColor()
{
    return textColor;
}

bool MatrixWebServices::initWifiManager()
{
    wifiManager = new WiFiManager();
    // for testing: wifiManager->resetSettings();
    custom_mqtt_server = new WiFiManagerParameter("Server", "mqtt server", mqttServer, 40);
    custom_mqtt_pw = new WiFiManagerParameter("password", "Password:", password, 40);
    custom_mqtt_machineId = new WiFiManagerParameter("MachineID", "MachineID:", id, 40);
    custom_mqtt_user = new WiFiManagerParameter("user", "UserName:", username, 40);

    wifiManager->addParameter(custom_mqtt_machineId);
    wifiManager->addParameter(custom_mqtt_server);
    wifiManager->addParameter(custom_mqtt_user);
    wifiManager->addParameter(custom_mqtt_pw);

    wifiManager->autoConnect("Led_Matrix", "12345678");
    wifiManager->stopWebPortal(); // needed so that we can connect to our custom addMachine portal.

    return true;
}

int MatrixWebServices::getScrolling()
{
    return isScrolling;
}

bool MatrixWebServices::initWifiClientSecure()
{
    Serial.print("connecting to WiFiClient secure...");

    client = new WiFiClient();
    while (!client)
    {
        Serial.print(".");
        delay(1000);
    }

    return true;
}
void MatrixWebServices::messagehandler(String &topic, String &payload)
{
    checkInput(topic, payload);
}
String MatrixWebServices::getText()
{
    return text;
}
void MatrixWebServices::checkInput(String &topic, String &payload)
{
    if (topic.equals(isScrollingTopic))
    {
        isScrolling = payload.toInt();
        // set is scrolling in textstate to true?
    }

    if (topic.equals(brightnessTopic))
    {

        brightness = payload.toInt();
        Matrix::isDirty = true;
    }
    if (topic.equals(imageTopic))
    {
        prevmenu = 2;

        free(image); // as strdup is not deleting the copy
        image = strdup(payload.c_str());
        Matrix::isDirty = true;
    }
    if (topic.equals(textTopic))
    {
        prevmenu = 4;

        text = payload;
        Matrix::isDirty = true;
    }
    if (topic.equals(snakeTopic))
    {
        prevmenu = 3;

        snakeDir = payload;
        Serial.println("Dir updpated!");
        Serial.println(snakeDir);
        Matrix::isDirty = true;
    }
    if (topic.equals(textColorTopic))
    {

        textColor = payload;
        Matrix::isDirty = true;
    }
    if (topic.equals(timeControlledTopic))
    {
        prevmenu = 0;
        free(timeControlledText); // as strdup is not deleting the copy
        timeControlledText = strdup(payload.c_str());
        Matrix::isDirty = true;
    }
}
char *MatrixWebServices::getTimeControlledString()
{
    return timeControlledText;
}
String MatrixWebServices::getSnakeDir()
{
    return snakeDir;
}
bool MatrixWebServices::initMQTTClient()
{
    // connect to aws endpoint with certificates and keys
    mqtt = new MQTTClient(4096); // 8192?
    mqtt->begin(custom_mqtt_server->getValue(), mqttPort, *client);

    Serial.print("connecting to mqtt broker...");
    while (!mqtt->connect(custom_mqtt_machineId->getValue(), custom_mqtt_user->getValue(), custom_mqtt_pw->getValue()))
    {
        Serial.print(".");
        delay(1000);
    };
    mqtt->publish(aliveTopic, "ALIVE_ESP!");
    // mqtt->subscribe(menuTopic, 2);
    mqtt->setWill("ESPISDEAD! ");

    mqtt->subscribe(textTopic, 2);
    mqtt->subscribe(imageTopic, 2);
    mqtt->subscribe(snakeTopic, 2);
    mqtt->subscribe(standbyTopic, 2);
    mqtt->subscribe(textColorTopic, 2);
    mqtt->subscribe(brightnessTopic, 2);
    mqtt->subscribe(timeControlledTopic, 2);
    mqtt->onMessage(messagehandler);
    return true;
}