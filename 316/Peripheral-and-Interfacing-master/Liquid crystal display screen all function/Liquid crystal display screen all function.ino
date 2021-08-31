#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

lcd.begin(16, 2);

lcd.print("hello world!");

}

void loop() { 
lcd.setCursor(16, 1);

  // set the display to automatically scroll:

  lcd.autoscroll();

  // print from 0 to 9:

  for (int thisChar = 0; thisChar < 10; thisChar++) {

    lcd.print(thisChar);

    delay(500);

  }

  // turn off automatic scrolling

  lcd.noAutoscroll();

  // clear screen for the next loop:

  lcd.clear();
  
  
  lcd.noBlink();

  delay(3000);

  // Turn on the blinking cursor:

  lcd.blink();

  delay(3000);
  
   // Turn off the cursor:

  lcd.noCursor();

  delay(500);

  // Turn on the cursor:

  lcd.cursor();

  delay(500);
  
  // Turn off the cursor:

  lcd.noCursor();

  delay(500);

  // Turn on the cursor:

  lcd.cursor();

  delay(500);
  
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
  
  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
    
    // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
  }
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  
}
  



