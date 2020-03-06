 #include <PRIZM.h>

 PRIZM prizm;

 int distance;
bool hasStopped=false;

void setup() {

  prizm.PrizmBegin();
  prizm.readSonicSensorCM(3);
  Serial.begin(9600);
  prizm.readLineSensor(3);
  prizm.setMotorInvert(1,1);
}

void loop() {
 distance = prizm.readSonicSensorCM(3);
 Serial.print(distance);
 Serial.print(" - ");
 prizm.setMotorSpeed(360,360);
if (distance<20){
  prizm.setServoPosition(1,100);
  prizm.setMotorPower(1,125);
  prizm.setMotorPower(2,125);
  delay(1000);
  prizm.setMotorPower(1,60);
  prizm.setMotorPower(2,-70);
  prizm.setMotorPower(125,125);
  delay(500);
  prizm.setMotorPower(1,100);
  prizm.setMotorPower(2,100);
  prizm.setMotorPower(125,125);
  delay(1000);
  prizm.setMotorPower(1,-35);
  prizm.setMotorPower(2,35);
  prizm.setMotorPower(125,125);
  delay(500);
  prizm.setMotorPower(1,75);
  prizm.setMotorPower(2,75);
  prizm.setMotorPower(125,125);
  delay(500);
  prizm.PrizmEnd();
  }
  else if (distance>20){
  prizm.setServoPosition(1,50);
  prizm.setMotorPower(1,50);
  prizm.setMotorPower(2,50);
}}

void forward(){
  prizm.setMotorPower(1,50);
  prizm.setMotorPower(2,50);
}

void TurnLeft(){
  prizm.setMotorPower(1,50);
  prizm.setMotorPower(2,25);
}

void TurnRight(){
  prizm.setMotorPower(1,50);
  prizm.setMotorPower(2,25);
}
void reverse(){
  prizm.setMotorPower(1,-25);
  prizm.setMotorPower(2,-25);
}
