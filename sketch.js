//Creation&Computation
//reads 2 sensor value from arduino
//draws a circle based on the analog sensor value
//change the color based on the button
//uses JSON as the protocol
//requires p5.serialcontrol to be running
//and arduino running the SerialInput_1button_1ana sketch

var serial;       //variable to hold the serial port object


var sensorValue0;      //this variable will hold the value from "s1"
var sensorValue1;      //this variable will hold the value from "s2"
var sensorValue2;

var serialPortName = "/dev/cu.usbmodem1431";  //FOR PC it will be COMX on mac it will be something like "/dev/cu.usbmodemXXXX"
                              //Look at P5 Serial to see the available ports
function setup() {
  
  createCanvas(1000,1000);
  //Setting up the serial port
  serial = new p5.SerialPort();     //create the serial port object
  serial.open(serialPortName); //open the serialport. determined 
  serial.on('open',ardCon);         //open the socket connection and execute the ardCon callback
  serial.on('data',dataReceived);   //when data is received execute the dataReceived function
}

function draw() {  
    fill(sensorValue0,sensorValue1,sensorValue2);
    ellipse(width/2,height/2, width/2, height/2); //apply the sensor value to the radius of the ellipse
  
  
}


function dataReceived()   //this function is called every time data is received
{
  
var rawData = serial.readStringUntil('\r\n'); //read the incoming string until it sees a newline
    console.log(rawData);                   //uncomment this line to see the incoming string in the console     
    if(rawData.length>1)                      //check that there is something in the string
    {                                         
      
      sensorValue0 = JSON.parse(rawData).s0;       //the parameter value .s1 must match the parameter name created within the arduino file
      sensorValue1 = JSON.parse(rawData).s1; 
    sensorValue2 = JSON.parse(rawData).s2; 
    }
}

function ardCon()
{
  console.log("connected to the arduino!! Listen UP");
}


