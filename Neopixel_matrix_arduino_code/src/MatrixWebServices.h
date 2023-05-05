#ifndef SODAWEBSERVICES_H
#define SODAWEBSERVICES_H
#define TIMEOUT 20000
#define UPDATETIMER 1500000 // how often we publish mqtt for all machines
#define TOPIC "/"

#include "WifiManager.h"
#include <MQTT.h>
#include <WiFiClient.h>
#include <SPIFFS.h>
#include <ESPmDNS.h>
#include <Matrix.h>
#include "time.h"

class MatrixWebServices
{
private:
    WiFiClient *client;

    MQTTClient *mqtt;

    WiFiManager *wifiManager;

    uint32_t prev_ms;

    int menuResult = 1;
    const char *mqttServer = "m2m.crabdance.com";
    const char *id = "ESP32";
    const char *username = "";
    const char *password = "";
    int mqttPort = 1883;
    WiFiManagerParameter *custom_mqtt_server;
    WiFiManagerParameter *custom_mqtt_pw;
    WiFiManagerParameter *custom_mqtt_user;
    WiFiManagerParameter *custom_mqtt_machineId;

public:
    MatrixWebServices()
    {

        initWifiManager();
        delay(1000);
        initWifiClientSecure();
        delay(1000);
        initMQTTClient();
        delay(1000);
        prev_ms = millis();

        Serial.println("WebServices successfully connected!");
    };

    ~MatrixWebServices(){};

    static char *getImg();
    static char *getTimeControlledString();

    static String getText();
    static String getColor();
    static String getSnakeDir();

    static int getBrightness();
    static int getScrolling();

    static void checkInput(String &topic, String &payload);
    static void messagehandler(String &topic, String &payload);

    bool initWifiClientSecure();
    bool initWifiManager();
    bool initMQTTClient();
    bool mainLoop();

    int readInputField();
};

#endif