#include <SoftwareSerial.h>
#include "ESP8266.h"
ESP8266 wifi(Serial);

SoftwareSerial mySerial(11, 10); // RX, TX(arduino的)

void setup()
{
  Serial.begin(115200);
  while (!Serial) 
  {
    ; 
  }


  Serial.println("");
  mySerial.begin(115200);
 
  mySerial.println("AT\n");//　直接先送出一個AT出去
}

void loop()
{ 
  if (mySerial.available())
  {
    Serial.write(mySerial.read());
  }
  if (Serial.available())
  {
    mySerial.write(Serial.read());
  }
}

