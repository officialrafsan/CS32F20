#include<SPI.h>
#include <SD.h>


const int trigPin = 9;
const int echoPin  = 8;
const int led = 7;
void setup(){
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  delay(2000);
}
File myFile;
uint16_t line = 1;

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

myFile = SD.open("test.txt", FILE_WRITE);

if (myFile) {
    Serial.print(line);
    Serial.print(":    Distance = ");
    Serial.println(distance);
    // Write data to SD card file (sensorData.txt)
    myFile.print(line++);
    myFile.print(":    Distance = ");
    myFile.println(distance);
    myFile.close();
    delay(500);
  }
else{
  Serial.println("no");
  }
    
if (distance < 10)
{ 
digitalWrite(led,HIGH);
}
else {
digitalWrite(led,LOW);
}
}
