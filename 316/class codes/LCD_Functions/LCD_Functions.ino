#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int thisChar = 'a';
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};
byte sad[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B01110,
  B10001,
  B00000,
};


void setup() {
lcd.begin(16, 2);

Serial.begin(9600);
char a;
Serial.print("Enter: ");
delay(3000);
if(Serial.available()>0){
  a=Serial.read();
  Serial.print(a);
  lcd.write(a);
}
delay(2000);
lcd.clear();
Serial.end();
lcd.print("Hello");
delay(1000);
lcd.home();
lcd.print("This is adib");
delay(1000);
lcd.clear();
lcd.setCursor(0,1);
lcd.print("This is 2nd line");
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.write('c');
lcd.cursor();
lcd.blink();
delay(1000);
lcd.noBlink();
delay(1000);
lcd.noCursor();
lcd.noDisplay();
delay(1000);
lcd.display();
delay(1000);
lcd.setCursor(0,0);
String msg="I study CSE in University of Asia Pacifi";
lcd.print(msg);
//delay(100);
for(int i=0;i< msg.length();i++){
  lcd.scrollDisplayLeft();
  delay(200);
}
lcd.clear();
delay(500);
String msg1="I am using different functions of LM016L";
lcd.print(msg1);
//delay(100);
for(int i=msg1.length();i>0;i--){
  lcd.scrollDisplayRight();
  delay(200);
}
lcd.clear();
delay(500);
lcd.write('a');
delay(500);
lcd.autoscroll();
lcd.write('b');
delay(500);
lcd.autoscroll();
lcd.write('c');
delay(500);
lcd.noAutoscroll();
lcd.write('d');
delay(500);

lcd.clear();
lcd.createChar(0, smiley);
lcd.createChar(1, sad);
lcd.begin(16, 2);  
lcd.write(byte(0));
lcd.write(byte(1));
delay(3000);
lcd.clear();

lcd.cursor();
}
void loop() {
 if (thisChar == 'm') {
    lcd.rightToLeft();
  }
  if (thisChar == 's') {
    lcd.leftToRight();
  }
  if (thisChar > 'z') {
    lcd.home();
    thisChar = 'a';
  }
  lcd.write(thisChar);
  delay(1000);
  thisChar++;





  
}
