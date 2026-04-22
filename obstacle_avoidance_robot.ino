#include <Servo.h>
#include <NewPing.h>

const int LeftMotorForward  = 7;
const int LeftMotorBackward = 6; // PWM
const int RightMotorForward = 5; // PWM
const int RightMotorBackward = 4;

#define trig_pin A1
#define echo_pin A2
#define maximum_distance 200

// Tuning Parameters
const int CENTER_ANGLE = 115;
const int RIGHT_ANGLE  = 55;
const int LEFT_ANGLE   = 170;
const int OBSTACLE_CM  = 35; 
const int TURN_SPEED   = 150; 
const int DRIVE_SPEED  = 200; 

NewPing sonar(trig_pin, echo_pin, maximum_distance);
Servo servo_motor;

void setup() {
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(10);
  servo_motor.write(CENTER_ANGLE);
  delay(2000); 
}

void loop() {
  int distance = readPing();

  if (distance > 60) {
    moveForward(220); 
  } else if (distance <= 60 && distance > OBSTACLE_CM) {
    moveForward(130); 
  } else {
    executeAvoidance(); 
  }
}

int readPing() {
  delay(30);
  int cm = sonar.ping_cm();
  return (cm == 0) ? 250 : cm;
}

void executeAvoidance() {
  moveStop();
  
  // Quick look left/right
  int dRight = lookRight();
  int dLeft = lookLeft();

  if (dRight < 20 && dLeft < 20) {
    // Both blocked: Back up and do a wide turn
    moveBackward(DRIVE_SPEED);
    delay(600);
    turnRight(TURN_SPEED);
    delay(600); 
  } else if (dRight >= dLeft) {
    turnRight(TURN_SPEED);
    delay(400);
  } else {
    turnLeft(TURN_SPEED);
    delay(400);
  }
  moveStop();
}

int lookRight() {
  servo_motor.write(RIGHT_ANGLE);
  delay(300);
  int d = readPing();
  servo_motor.write(CENTER_ANGLE);
  return d;
}

int lookLeft() {
  servo_motor.write(LEFT_ANGLE);
  delay(300);
  int d = readPing();
  servo_motor.write(CENTER_ANGLE);
  return d;
}

// Speed-controlled movement functions
void moveForward(int speed) {
  analogWrite(LeftMotorForward, speed);
  analogWrite(RightMotorForward, speed);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void moveBackward(int speed) {
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  analogWrite(LeftMotorBackward, speed);
  analogWrite(RightMotorBackward, speed);
}

void turnRight(int speed) {
  analogWrite(LeftMotorForward, speed);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  analogWrite(RightMotorBackward, speed);
}

void turnLeft(int speed) {
  digitalWrite(LeftMotorForward, LOW);
  analogWrite(RightMotorForward, speed);
  analogWrite(LeftMotorBackward, speed);
  digitalWrite(RightMotorBackward, LOW);
}

void moveStop() {
  // Brief reverse pulse to counter momentum
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  analogWrite(LeftMotorBackward, 255); 
  analogWrite(RightMotorBackward, 255);
  delay(50); 
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}