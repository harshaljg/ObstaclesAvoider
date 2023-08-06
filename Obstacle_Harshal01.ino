#include <Servo.h>

Servo servo;

const int trigPinFront = 9;
const int echoPinFront = 10;
const int trigPinBack = 11;
const int echoPinBack = 12;
const int trigPinLeft = 5;
const int echoPinLeft = 6;
const int trigPinRight = 7;
const int echoPinRight = 8;
const int threshold = 20;
const int speed = 150;

void setup() {
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinBack, OUTPUT);
  pinMode(echoPinBack, INPUT);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  servo.attach(4);
}

void loop() {
  int durationFront, distanceFront;
  digitalWrite(trigPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFront, LOW);
  durationFront = pulseIn(echoPinFront, HIGH);
  distanceFront = durationFront * 0.034 / 2;

  int durationBack, distanceBack;
  digitalWrite(trigPinBack, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinBack, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinBack, LOW);
  durationBack = pulseIn(echoPinBack, HIGH);
  distanceBack = durationBack * 0.034 / 2;

  int durationLeft, distanceLeft;
  digitalWrite(trigPinLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);
  durationLeft = pulseIn(echoPinLeft, HIGH);
  distanceLeft = durationLeft * 0.034 / 2;

  int durationRight, distanceRight;
  digitalWrite(trigPinRight, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW);
  durationRight = pulseIn(echoPinRight, HIGH);
  distanceRight = durationRight * 0.034 / 2;

  if (distanceFront > threshold && distanceLeft > threshold && distanceRight > threshold) {
    servo.write(90);
    analogWrite(5, speed);
    analogWrite(6, speed);
  } else if (distanceFront <= threshold && distanceBack > threshold && distanceLeft > threshold && distanceRight > threshold) {
    servo.write(45);
    analogWrite(5, 0);
    analogWrite(6, speed);
    delay(500);
    analogWrite(5, speed);
    analogWrite(6, speed);
    delay(500);
  } else if (distanceFront > threshold && distanceBack <= threshold && distanceLeft > threshold && distanceRight > threshold) {
    servo.write(135);
    analogWrite(5, speed);
    analogWrite(6, 0);
    delay(500);
    analogWrite(5, speed);
    analogWrite(6, speed);
    delay(500);
  } else if (distanceFront > threshold && distanceBack > threshold && distanceLeft <= threshold && distanceRight > threshold) {
    servo.write(0);
    analogWrite(5, speed);
    analogWrite(6, 0);
  }
}

   
