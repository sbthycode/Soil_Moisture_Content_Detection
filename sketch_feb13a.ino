
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "7plYNKwCnKXhLitVx2shF4ZWnFR3OaUO";  //code sent via email
const int sensorPin = 17;
int sensorState = 0;
int lastState = 0;


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "WifiLelo..", "WifiDedo");  //wifi name and password
  pinMode(sensorPin, INPUT);
  Blynk.notify("Your plant is monitored");
}

void loop()
{
  Blynk.run();

  sensorState = analogRead(sensorPin);
  Serial.println(sensorState);

  if (sensorState >= 750 && lastState == 0) {
    Serial.println("needs water, send notification");
    Blynk.notify("Time To Water The Plants");
    lastState = 1;
    delay(1000);
    //send notification

  }
  else if (sensorState >= 750 && lastState == 1) {
    //do nothing, has not been watered yet
    Serial.println("has not been watered yet");
    delay(1000);
  }
  else {
    //st
    Serial.println("does not need water");
    lastState = 0;
    delay(1000);
  }
  
   

  delay(100);
}
