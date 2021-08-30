#include <Servo.h>

Servo VServo;
Servo HServo;

int VServoPin = 5;
int VAngle = 90; //starting angle
int MaxVAngle = 150;
int MinVAngle = 45;

int HServoPin = 6;
int HAngle = 90; //starting angle
int MaxHAngle = 150;
int MinHAngle = 20;


int threshold = 8; //how much of a difference is significant?
int waittime = 10; //how often should we sample values and adjust accordingly?
int upleft= A0; //our serial data-in ports
int upright= A1;
int downleft= A2;
int downright= A3;

void setup() {

  Serial.begin(9600); //sets up  a serial data connection so we can plot/see values
  pinMode(3, OUTPUT); //how we measure voltage drop across photo-resistors, we have to supply some voltage to it to begin with
  VServo.attach(VServoPin);
  HServo.attach(HServoPin);
}

void loop() {
  digitalWrite(3, HIGH); //now we will see the voltage drop
  int ULVal = analogRead(upleft);
  int URVal = analogRead(upright);
  int DLVal = analogRead(downleft);
  int DRVal = analogRead(downright);
  
  // print out the value you read:
  char my_str[] = "hello";
  Serial.print("UL: ");
  Serial.print(ULVal);
  Serial.print(", UR: ");
  Serial.print(URVal);
  Serial.print(", DL: ");
  Serial.print(DLVal);
  Serial.print(", DR: ");
  Serial.println(DRVal);
  delay(waittime);        // delay in between reads for stability 
 
  //adjust horizontal equilibrium
  if(ULVal > (URVal+threshold)){
    HAngle += 1;
    delay(waittime);
  }
  HServo.write(HAngle);
  if(DLVal > (DRVal+threshold)){
    HAngle += 1;
    delay(waittime);
  }  
  HServo.write(HAngle);
  if(ULVal < (URVal - threshold)){
    HAngle -= 1;
    delay(waittime);
  }
  HServo.write(HAngle);
  if(DLVal < (DRVal - threshold)){
    HAngle -= 1;
    delay(waittime);
  }
  HServo.write(HAngle);
  if(HAngle > MaxHAngle){
    HAngle = MaxHAngle;
  }
  else if(HAngle < MinHAngle){
    HAngle = MinHAngle;
  }

  //adjust vertical equilibrium
  if(ULVal < (DLVal-threshold)){
    VAngle += 1;
    delay(waittime);
  }
  VServo.write(VAngle);
  if(URVal < (DRVal-threshold)){
    VAngle += 1;
    delay(waittime);
  }  
  VServo.write(VAngle);
  if(ULVal > (DLVal + threshold)){
    VAngle -= 1;
    delay(waittime);
  }
  VServo.write(VAngle);
  if(URVal > (DRVal + threshold)){
    VAngle -= 1;
    delay(waittime);
  }
  VServo.write(VAngle);
  if(VAngle > MaxVAngle){
    VAngle = MaxVAngle;
  }
  else if(VAngle < MinVAngle){
    VAngle = MinVAngle;
  }
  
}
