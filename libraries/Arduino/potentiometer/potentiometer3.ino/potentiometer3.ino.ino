 #include <ArduinoJson.h>

unsigned long lastSend;
int sendRate = 50;
 
 void setup() {
   // configure the serial connection:
   Serial.begin(9600);
   // configure the digital input:
 }
 
void loop() {

   int sensorValue0 = map(analogRead(A0),0,1023,0,255);
   int sensorValue1 = map(analogRead(A1),0,1023,0,255);
   int sensorValue2 = map(analogRead(A2),0,1023,0,255);

                                    //print a \n character to the serial port to distinguish between objects
  
   if(millis()-lastSend>=sendRate)                           //use a timer to stablize the data send
{
////////////////////////////////////////////////////////////send the values to P5 over serial
  DynamicJsonBuffer messageBuffer(200);                   //create the Buffer for the JSON object        
  JsonObject& p5Send = messageBuffer.createObject();      //create a JsonObject variable in that buffer       
  
  p5Send["s0"] = sensorValue0;                               //assign buttonValue to the key "s1" in the json object
  p5Send["s1"] = sensorValue1;                                  //assign anaValue to the key "s2" in the json object 
  p5Send["s2"] = sensorValue2;

  p5Send.printTo(Serial);                                 //print JSON object as a string
  Serial.println();                                       //print a \n character to the serial port to distinguish between objects

lastSend = millis();
}  

}
