
// Read a card using a mfrc522 reader on your SPI interface

#include <SPI.h>
#include <RFID.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

RFID rfid(53,5);// assigns set and reset pins for mega 2560
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// variables to represent each rfid sensor's five, 3 digit codes:
int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  SPI.begin();
  rfid.init();
}
void loop()
{
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {// reads card and puts values into array
      if (rfid.serNum[0] != serNum0 
          && rfid.serNum[1] != serNum1
          && rfid.serNum[2] != serNum2
          && rfid.serNum[3] != serNum3
          && rfid.serNum[4] != serNum4
         ) {

        lcd.setCursor(0, 0);
        //lcd.print("Card # (DEC):");
        lcd.print("Card #: ");
        lcd.print(rfid.serNum[0], DEC);
        lcd.print(' ');
        lcd.print(rfid.serNum[1], DEC);
        lcd.setCursor(0, 1);
        lcd.print(rfid.serNum[2], DEC);
        lcd.print(' ');
        lcd.print(rfid.serNum[3], DEC);
        lcd.print(' ');
        lcd.print(rfid.serNum[4], DEC);
      }
    }
  }

  rfid.halt();
}
