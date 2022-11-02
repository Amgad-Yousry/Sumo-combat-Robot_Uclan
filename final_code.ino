#include<ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>
int servoM4 = TK4, servoM0 = TK0;
int trigPinl =TKD3 ;    //Trig - green Jumper
int echoPinl = TKD4;//Echo - yellow Jumper
int trigpinR = TKD0;
int backwardreader = TK7;
long duration, cm, inches;
void setup() {
  Serial.begin(9600);
  Robot.begin();
  pinMode(servoM4, OUTPUT);
  pinMode(servoM0, OUTPUT);
  pinMode(trigPinl, OUTPUT);
  pinMode(echoPinl, INPUT);
  pinMode (trigpinR,OUTPUT);
  delay(2000);
  
  Robot.motorsWrite(-180,-120);
  delay (2000);
  Robot.motorsWrite (0,0);
  
  // put your setup code here, to run once:

}

void loop() {
   int forwardReader = Robot.analogRead(TK2);
  int backwardreader =  Robot.analogRead(TK7);
    Robot.digitalWrite(trigPinl, LOW);
    Robot.digitalWrite(trigPinl,LOW);
  delayMicroseconds(5);
  Robot.digitalWrite(trigPinl, HIGH);
  Robot.digitalWrite(trigpinR,HIGH);
  delayMicroseconds(10);
  Robot.digitalWrite(trigPinl, LOW);
  Robot.digitalWrite(trigpinR,LOW);
   pinMode(echoPinl, INPUT);
  duration = pulseIn(echoPinl, HIGH);
  cm = (duration/2) / 29.1;
 
  Robot.updateIR(); // update the IR array
  Robot.motorsWrite(160,120);
   for (int i = 0; i < 5; i++){
    int a=Robot.digitalRead(Robot.IRarray[i]);
    delay(50);
 if(a>900)
   { Robot.motorsWrite(255,-255);
    delay (1500);
    Robot.motorsWrite(255,255);
    delay(1000);  
    }  
    else if (forwardReader>200 && a<800 || cm < 30 ){
    Robot.motorsWrite(255,255);
    delay (100);
    Robot.motorsWrite(255,255);}
    else if (backwardreader >60 && a <800 ) {
      Robot.motorsWrite(255,200);
      delay (3000);}
      else if ( cm <15 && a < 800 ) {
        Robot.motorsWrite (255,-255);
        delay(2000);
      }
    
    else {
    Robot.motorsWrite(160,255);
    delay (500);
    Robot.motorsWrite(0,0);
    delay (500);
    Robot.motorsWrite(255,160);
    delay (500);
    Robot.motorsWrite (0,0);
    delay(500);
    }}}

  
   
    
