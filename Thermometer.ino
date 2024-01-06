#include <math.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
void chooseRightOne(int);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int arr[] = {2, 4, 5, 6, 7, 8, 9};
void setup()
{
  for (int i = 0; i < 7; i++){
    pinMode(arr[i], OUTPUT);
  }
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}
void loop()
{
  double val = analogRead(0);
  double fenya = (val/1023)*5;
  double r = fenya/(5-fenya)*10000;
  double temp = 1/(log(r/10000) /3950 + 1/(25+273.15))-273.15;
  if (temp < -30){
    chooseRightOne(9);
    tone(10, 100);
  }
  else if (temp > -30 && temp <= 0){
    chooseRightOne(8);
    tone(10, 200);
  }
  else if (temp > 0 && temp <= 30){
    chooseRightOne(7);
    tone(10, 300);
  }
  else if (temp > 30 && temp <= 60){
    chooseRightOne(6);
    tone(10, 400);
  }
  else if (temp > 60 && temp <= 75){
    chooseRightOne(5);
    tone(10, 500);
  } 
  else if (temp > 75 && temp <= 90){
    chooseRightOne(4);
    tone(10, 600);
  }
  else{
    chooseRightOne(2);
    tone(10, 700);
  }
  lcd.setCursor(0, 0);
  lcd.println("Tempature: ");

  lcd.setCursor(0, 1);
  lcd.println(temp);
  delay(100);
}

void chooseRightOne(int LED){
  for (int i = 0; i < 7; i++){
    if (arr[i] == LED){
      digitalWrite(arr[i], HIGH);
    }
    else{
      digitalWrite(arr[i], LOW);
    }
  }
}