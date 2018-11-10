#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>

#define PIN 9
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

unsigned long lastSend;
int sendRate = 50;

 void setup() 
 {
  Serial.begin(9600);    // configure the serial connection:
  pinMode(A0, INPUT_PULLUP);
  strip.begin();
  strip.show();
 }




 
void loop() 
{
   int sensorValue0 = map(analogRead(A0),0,1023,0,101)/2; //potentiometer1
   int sensorValue1 = map(analogRead(A1),0,1023,0,101); //potentiometer2
   int sensorValue2 = map(analogRead(A2),0,1023,0,800); //potentiometer3
   int sensorValue3 = map(analogRead(A3),0,1023,0,255); //slider1
   int sensorValue4 = map(analogRead(A4),0,1023,0,255); //slider2
   int sensorValue5 = map(analogRead(A5),0,1023,0,255); //slider3

  strip.setPixelColor(0, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(1, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(2, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(3, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(4, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(5, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(6, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(7, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(8, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(9, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(10, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(11, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(12, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(13, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(14, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(15, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(16, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(17, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(18, sensorValue3, sensorValue4, sensorValue5);
  strip.setPixelColor(19, sensorValue3, sensorValue4, sensorValue5);
  strip.show();

  
   if(millis()-lastSend>=sendRate)                           //use a timer to stablize the data send
{
////////////////////////////////////////////////////////////send the values to P5 over serial
  DynamicJsonBuffer messageBuffer(200);                   //create the Buffer for the JSON object        
  JsonObject& p5Send = messageBuffer.createObject();      //create a JsonObject variable in that buffer       
  
  p5Send["s0"] = sensorValue0;                               //assign buttonValue to the key "s1" in the json object
  p5Send["s1"] = sensorValue1;                                  //assign anaValue to the key "s2" in the json object 
  p5Send["s2"] = sensorValue2;
  p5Send["s3"] = sensorValue3;
  p5Send["s4"] = sensorValue4;
  p5Send["s5"] = sensorValue5;

  p5Send.printTo(Serial);                                 //print JSON object as a string
  Serial.println();                                       //print a \n character to the serial port to distinguish between objects

  delay(50);
lastSend = millis();
}  

}
