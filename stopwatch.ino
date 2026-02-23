// Project 26 - Digital Stopwatch

#include <LiquidCrystal.h>

#define btnSELECT 4
#define btnNONE   5
long offset=0;
LiquidCrystal lcd(8,9,4,5,6,7);    //Select pins used

unsigned long starting, finished, elapsed;

int lcd_key     = 0;
int adc_key_in  = 0;

int read_LCD_buttons(){               // read the buttons
    adc_key_in = analogRead(0);       // read the value from the sensor 

    if (adc_key_in < 850 && adc_key_in > 651)  return btnSELECT; 

    else return btnNONE;    
}

void setup()
{
  lcd.begin (16,2);   //starts the library
  lcd.setCursor (0,0);
  lcd.print ("  :  :  :");
}

void loop()
{
  long m=millis()-offset;
  int hours = (m / 3600000) % 100;   
  int minutes = (m / 60000) % 60;    
  int seconds = (m / 1000) % 60;     
  int ms = (m / 10) % 100;          
  

  lcd.setCursor(0, 0);
  lcd.print(hours);

  lcd.setCursor(3, 0);
  lcd.print(minutes);
  
  lcd.setCursor(6, 0);
  lcd.print(seconds);
  
  lcd.setCursor(9, 0);
  lcd.print(ms);

  lcd_key = read_LCD_buttons();   // read the buttons

    switch (lcd_key){             

      case btnSELECT:{
        delay(5000);              // stop counting for 5 seconds
        offset+=5000;             // add 5 seconds to timer to act as an offset because you cant pause a internal clock
        break;
       }
      case btnNONE:{
        break;
       }
   }

}