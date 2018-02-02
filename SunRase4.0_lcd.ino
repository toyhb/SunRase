#include <LiquidCrystal.h>
const int tempPin = A0;
const int batPin = A1;
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
void setup() {
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
 lcd.setCursor(0, 0);
 lcd.print("Temp. Driver:");
 lcd.print(temp());
 lcd.setCursor(0, 1);
 lcd.print("Batteria:");
 lcd.print(batteria());
 lcd.print("%");
 lcd.clear();
}
float temp(){
  int tempVal = analogRead(tempPin);
  float millivolts = (tempVal / 1024.0) * 5000;
  float celsius = millivolts / 10;
  return celsius;
}
int batteria(){
  int batVal = analogRead(batPin);
  int batX100 = (batVal * 100) / 1024;
  return batX100;
}
