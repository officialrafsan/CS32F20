#include <LiquidCrystal.h>
const int trigPin = 9;
const int echoPin  = 10;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.begin(16, 2);

}

void loop() {
 long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) * 0.034;
lcd.println(distance);

  }
