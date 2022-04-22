
#include <Servo.h>

Servo VServo;
Servo HServo;

int VServoPin = 5;
int MaxVAngle = 130;
int MinVAngle = 80;
int VAngle;

int HServoPin = 6;
int MaxHAngle = 150;
int MinHAngle = 20;
int HAngle;

int MotorWait = 50;


void setup() {
  //pinMode(5, OUTPUT); 
  VServo.attach(VServoPin);
  HServo.attach(HServoPin);
}

void loop() {
  //analogWrite(5, 0);
  //  VServo.write(40);
  
  delay(1000);
  VAngle = MinVAngle;
  HAngle = MinHAngle;
  
  
  //turn the servos from their min angles to their max angles
  while(VAngle < MaxVAngle){
    VServo.write(VAngle); //This is a line you can put "//" in front of to comment out
    //*HServo.write(HAngle); //This is a line you can put "//" in front of to comment out
  
    delay(MotorWait);
    VAngle = VAngle + 1;
    
    //*if(HAngle < MaxHAngle){
    //*  HAngle = HAngle + 1;
    //*}
  
  }
  while(HAngle < MaxHAngle){
    //*VServo.write(VAngle); //This is a line you can put "//" in front of to comment out
    HServo.write(HAngle); //This is a line you can put "//" in front of to comment out
  
    delay(MotorWait); 
    
    //*if(VAngle < MaxVAngle){ 
    //*  VAngle = VAngle + 1;
    //*}
    
    HAngle = HAngle + 1;
  
  }
  
  
  //turn the servos from their max angles to their min angles
  while(VAngle > MinVAngle){
    VServo.write(VAngle);
    //*HServo.write(HAngle);
    delay(MotorWait); 
    VAngle = VAngle - 1;
    //*HAngle = HAngle - 1;
  
  }
  while(HAngle > MinHAngle){
    //*VServo.write(VAngle);
    HServo.write(HAngle);
    delay(MotorWait); 
    //*VAngle = VAngle - 1;
    HAngle = HAngle - 1;
  
  }



}
