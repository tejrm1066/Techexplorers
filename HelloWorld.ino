// use library LiquidCrystal_V1.2.1 for Arduino IDE 1.6.3 and earlier
// Use library LiquidCrystal_V1.3.4 when Arduino IDE 1.8.3 is used. 

#include <Wire.h>
#include <LiquidCrystal_I2C.h>//Load Liquid Crystal Library

LiquidCrystal_I2C LCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup() {
LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
}
 
void loop() {
  LCD.setCursor(2,0);// tells arduino to start printing on second column, upper row
  LCD.print("Hello World!");  //Print Message on First Row
 }

