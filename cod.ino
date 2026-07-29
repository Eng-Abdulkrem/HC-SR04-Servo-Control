#include <Servo.h>

Servo myServo;

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  myServo.attach(3);
  myServo.write(0);   // الوضع الأصلي

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {

  // إرسال نبضة للحساس
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // استقبال النبضة
  duration = pulseIn(echoPin, HIGH);

  // حساب المسافة
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (distance <= 10) {
    myServo.write(90);      // يتحرك إلى 90 درجة
  } else {
    myServo.write(0);       // يرجع للوضع الأصلي
  }

  delay(100);
}