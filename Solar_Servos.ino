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
VServo.attach(VServoPin);
HServo.attach(HServoPin);
}

void loop() {

delay(1000);
VAngle = MinVAngle;
HAngle = MinHAngle;


//turn the servos from their min angles to their max angles
while(VAngle < MaxVAngle){
  VServo.write(VAngle);

  delay(MotorWait);
  VAngle = VAngle + 1;
}

while(HAngle < MaxHAngle){
  HServo.write(HAngle);

  delay(MotorWait); 
  HAngle = HAngle + 1;
}


//turn the servos from their max angles to their min angles
while(VAngle > MinVAngle){
  VServo.write(VAngle);
  delay(MotorWait); 
  VAngle = VAngle - 1;
}

while(HAngle > MinHAngle){
  HServo.write(HAngle);
  delay(MotorWait); 
  HAngle = HAngle - 1;

}



}
