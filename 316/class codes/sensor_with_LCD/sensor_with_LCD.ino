#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int trigPin = 13;

const int echoPin = 12;

const int led = 11;
void setup() {

lcd.begin(16, 2);
pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(led, OUTPUT);


}

void loop()

{
long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = (duration/2) * 0.034;
lcd.setCursor(0,0);
lcd.print("The distance is: ");
lcd.setCursor(0,1);
lcd.print(distance);
delay(500);
lcd.clear();
if (distance < 10)
{ 
digitalWrite(led,HIGH);
}
else {
digitalWrite(led,LOW);
}



}
