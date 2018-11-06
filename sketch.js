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
var sensorValue3;
var sensorValue4;
var sensorValue5;

var serialPortName = "/dev/cu.usbmodem1421";  //FOR PC it will be COMX on mac it will be something like "/dev/cu.usbmodemXXXX"
                              //Look at P5 Serial to see the available ports
function setup() {
  
  createCanvas(windowWidth, windowHeight);
  //Setting up the serial port
  serial = new p5.SerialPort();     //create the serial port object
  serial.open(serialPortName); //open the serialport. determined 
  serial.on('open',ardCon);         //open the socket connection and execute the ardCon callback
  serial.on('data',dataReceived);   //when data is received execute the dataReceived function
}

function draw() 
{  
    background(sensorValue3,sensorValue4,sensorValue5);  
    
    push();
    translate(width*0.8, height*0.5);
    rotate(frameCount / sensorValue1);
    polygon(0,0, sensorValue2, sensorValue0); 
    pop();
}

function polygon(x, y, radius, npoints) {
  var angle = TWO_PI / npoints;
  beginShape();
  for (var a = 0; a < TWO_PI; a += angle) {
    var sx = x + cos(a) * radius;
    var sy = y + sin(a) * radius;
    vertex(sx, sy);
  }
  endShape(CLOSE);
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
    sensorValue3 = JSON.parse(rawData).s3;
    sensorValue4 = JSON.parse(rawData).s4;
    sensorValue5 = JSON.parse(rawData).s5;
    }
}

function ardCon()
{
  console.log("connected to the arduino!! Listen UP");
}


