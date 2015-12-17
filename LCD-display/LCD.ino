
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);  
  // Permanet mensages
  lcd.setCursor(0, 1);
  lcd.print("LCD DISPLAY");

}

void loop() {

  lcd.setCursor(0, 0);
  // Second counter
  lcd.print(millis() / 1000);
  

  
}

