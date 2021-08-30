 /*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code has been adapted from an Arduino package that is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int sensor1= A0;
int sensor2= A1;
int sensor3= A2;
int sensor4= A3;

// the setup routine runs once at the beginning and when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  digitalWrite(3, HIGH);
  int sensorValue1 = analogRead(sensor1);
  int sensorValue2 = analogRead(sensor2);
  int sensorValue3 = analogRead(sensor3);
  int sensorValue4 = analogRead(sensor4);
  
  // print out the value you read:
  Serial.print("1: ");
  Serial.print(sensorValue1);
  Serial.print(", 2: ");
  Serial.print(sensorValue2);
  Serial.print(", 3: ");
  Serial.print(sensorValue3);
  Serial.print(", 4: ");
  Serial.println(sensorValue4);
  delay(50);        // delay in between reads for stability
}
