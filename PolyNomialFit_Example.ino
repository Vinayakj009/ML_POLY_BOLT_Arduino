#include <BoltIot-Arduino-Helper.h>

void setup() {
  pinMode(A0,INPUT);        //Set A0 pin as input
  boltiot.Begin(Serial);    //Initialize Bolt module on serial port

}

void loop() {
  float temperature=(analogRead(A0)*500.0)/1024.0; //pull temperature data from LM35 sensor in Degree Celsius
  //temperature=32+(1.8*temperature); //uncomment this code line to push the temperature data in Fahrenheit.
  boltiot.CheckPoll(temperature);   //Check if Bolt cloud has asked for data, and push data to cloud.
}
