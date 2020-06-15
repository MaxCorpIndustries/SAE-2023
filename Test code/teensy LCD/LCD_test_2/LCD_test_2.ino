// include the library code:
#include <LiquidCrystal.h>

// Initialize the library with the interface pins
//LiquidCrystal lcd(2,3 , 5, 4, 3, 2);
LiquidCrystal lcd(3, 4, 16, 15, 14, 13);

void setup() {
// set up the LCD's number of columns and rows
lcd.begin(16, 2);
// Print a message to the LCD
lcd.print("hello world!");
}


void loop() {
// set the cursor to column 0, line 1
// (line 1 is the second row, since counting begins with 0)
lcd.setCursor(0, 1);
// print the number of seconds since reset:
lcd.print(millis()/1000);
}
