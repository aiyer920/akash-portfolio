#include <Servo.h>
#define CLK 11
#define DT 10
#define SW 9
unsigned long lastRemoteRead = 0;
const unsigned long remoteInterval = 200;
int counter2=0;
int currentStateCLK;
int lastStateCLK;
String currentDir = "";

Servo servoLock;
int servPin = 4;
int angleLock = 73
; //greater angle lifts J lock higher, less angle brings it lower, angleLock 71, angleRelease 145 for og servo
int angleRelease = 145;

int remote = A0;
int revolutions = 0;
const int DCforward = 8;    //Pin connected to H bridge input 2
const int DCbackward = 12;  //Pin connected to H bridge input 1
int delayTime = 2000;
int counter=0;

void setup() {
  // put your setup code here, to run once:
  servoLock.attach(servPin);
  pinMode(DCforward, OUTPUT);
  pinMode(DCbackward, OUTPUT);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);  // Initialize serial communication for debugging (optional)
  lastStateCLK = digitalRead(CLK);
  servoLock.write(angleRelease);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastRemoteRead >= remoteInterval) {
    lastRemoteRead = currentMillis;

    int remoteVal = analogRead(remote);
    if (remoteVal < 512) {
      counter++;
  }
}
  TapSensor(counter);
  if (counter==1) {
    int MotorState = MoveMotor(counter);
    int ServoState = MoveServo(counter);
  }
  if (counter==2){
    digitalWrite(DCforward, LOW);
    digitalWrite(DCbackward, LOW);
  }
  
  if (counter==3) {
    int ServoState = MoveServo(counter);
    if (ServoState == 1) {
    }
    counter=0;
  }
 
}

int TapSensor(int RF) {
  
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter2++;
      currentDir = "CCW";
    } else {
      // Encoder is rotating CW so increment
      counter2++;
      currentDir = "CW";
    }
    if (counter2 % 20 == 0){
      revolutions++;
    }
  }
  // Remember last CLK state
  lastStateCLK = currentStateCLK;

  // Put in a slight delay to help debounce the reading
  delay(1);
}

int MoveMotor(int RF) {
  int maxWind = 5;
  if (revolutions < maxWind) {
    digitalWrite(DCforward, HIGH);
    digitalWrite(DCbackward, LOW);
    return 0;
  }
  if (revolutions == maxWind) {
    digitalWrite(DCforward, LOW);
    digitalWrite(DCbackward, LOW);
    delay(delayTime);
    revolutions++;
    return 1;
  }
  if (revolutions > maxWind && revolutions < 2 * maxWind + 1) {
    digitalWrite(DCforward, LOW);
    digitalWrite(DCbackward, HIGH);
    return 2;
  }
  if (revolutions == 2 * maxWind + 1) {
    digitalWrite(DCforward, LOW);
    digitalWrite(DCbackward, LOW);
    return 3;
  }
}


int MoveServo(int RF) {
  float lock = 4;
  if (revolutions == lock) {
    servoLock.write(angleLock);
    return 0;
  }
  if (counter==3) {
    servoLock.write(angleRelease);
    revolutions = 0;
    return 1;
  }
}
