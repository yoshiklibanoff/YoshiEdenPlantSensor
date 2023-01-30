#include <Adafruit_AHT10.h> 
Adafruit_AHT10 aht;
#include <Wire.h>  // i2c communication 
#include "Sodaq_DS3231.h"

char weekDay[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
DateTime dt(2022, 12, 27, 12, 26, 0,   2);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  Serial.println("Adafruit AHT10 demo!");

  if (! aht.begin()) { // .init code 
    Serial.println("Could not find AHT10? Check wiring");
    while (1) delay(10);
  }
  Serial.println("AHT10 found"); 
  
  // RTC INIT
    Wire.begin();
    rtc.begin ();
    rtc.setDateTime(dt);
}

void loop() {
  //read AHT10
 sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  
  //read RTC
DateTime now = rtc.now(); //get the current date-time

  //print both to serial
Serial.println("Timestamp, Temperature, Humidity, Light intensity ");

Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.date(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    
Serial.print(temp.temperature);Serial.print(", ");
Serial.print( humidity.relative_humidity );Serial.print(", "); 
 

  
    

  
 // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  // print out the value you read:
 
float math = (sensorValue / 1023.) * 5;
Serial.print(sensorValue);
Serial.println(math);
 
  delay (500); 

 
}
