// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  // Print a message to the LCD.
  lcd.print("Hi");
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
  lcd.clear();
  int a=analogRead(A0);
  int b=analogRead(A1);
  int c=analogRead(A2);
  int d=analogRead(A3);
 
  int tot=a+b+c+d;
  //Serial.println(a);
  float A=(tot+1)/1024.00*5/4;
  //Serial.println(A);
  int ans= A*500;
  Serial.println(ans);
  lcd.setCursor(0, 0);
  lcd.print(ans);
  // print the number of seconds since reset:
  lcd.setCursor(0, 1);
  lcd.print("Lux");
  delay(500);
}


