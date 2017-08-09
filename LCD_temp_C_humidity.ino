#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
dht11 DHT11;
#define DHT11PIN 2

void setup()  
{
  LCD.begin(16,2);         
  LCD.setCursor(0, 0);
  LCD.print("DHT11 Temp/Humid");
}

void loop()   
{
 int chk = DHT11.read(DHT11PIN);//read data on pin 9 and assign it to variable named chk
  LCD.setCursor(0, 1);
  LCD.print(" C=");
  LCD.print((float)DHT11.temperature, 0); //returns temp in celsius, 0 decimal place precision
  LCD.print("  H=");
  LCD.print((float)DHT11.humidity, 1);//returns humidity in percent, 1 decimal place precision
  LCD.print("%");
  delay(2000);
}


