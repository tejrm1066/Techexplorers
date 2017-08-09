// basic RC522 code reader for RFID
#include <SPI.h> // library for serial communication between arduino and RFID Reader
#include <RFID.h> // library for RC522 RFID Reader
#include <LiquidCrystal_I2C.h> // library for LCD to Arduino I2C communication
#include <Wire.h>  //library for LCD
int firstnum,secnum,thirdnum;
RFID rfid(53, 5);  //similar to a pinMode command
LiquidCrystal_I2C LCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  LCD.begin(16, 2);
  SPI.begin();
  rfid.init(); // starts RFID reader
}

void loop()
{
  if (rfid.isCard()) {
    rfid.readCardSerial();
    firstnum = rfid.serNum[0], DEC;
    secnum = rfid.serNum[1], DEC;
    thirdnum = rfid.serNum[2], DEC;
    if ((firstnum == 212)&&(secnum==121)) {// use first and sec # of first rfid tag
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
    }
    else if ((firstnum == 46)&&(secnum==89)) {// use first and sec # of second rfid tag
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
    }

    else {
      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    }
  }

  rfid.halt(); // stops RFID reader
}
