#include <Arduino.h>
#include "StateMachine.h"

StateMachine *stateMachine;

void setup()
{
  Serial.begin(11520);
  delay(2000); // wait for serial
  stateMachine = new StateMachine();
}

void loop()
{
  stateMachine->mainLoop();
}