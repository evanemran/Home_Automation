#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
char* password = "1234"; //create a password
int pozisyon = 0;
int c=0;//keypad position

const byte rows = 4; //number of the keypad's rows and columns
const byte cols = 4;

char keyMap [rows] [cols] = { //define the cymbols on the buttons of the keypad

  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [rows] = {8, 7, 6, 5}; //pins of the keypad
byte colPins [cols] = {4, 3, 2, 1};
Servo servo;
int degree = 90;
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);

LiquidCrystal lcd (A0, A1, A2, A3, A4, A5); // pins of the LCD. (RS, E, D4, D5, D6, D7)

void setup(){
  lcd.begin(16, 2);
  servo.attach(0);
  servo.write(0);
  setLocked (true); //state of the password
}

void loop(){

  char whichKey = myKeypad.getKey(); //define which key is pressed with getKey

if(c==0)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    Welcome");
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password ");
}


  if(whichKey == '#' || whichKey == '*' || whichKey == 'A' ||       //define invalid keys
  whichKey == 'C' || whichKey == 'D'){

    pozisyon=0;
    setLocked (true);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Invalid Key!");
    delay(1000);
    lcd.clear();
  }

  if(whichKey == '1' || whichKey == '2' || whichKey == '3' ||       //define keys
  whichKey == '4' || whichKey == '5' || whichKey == '6' || whichKey == '7' || whichKey == '8' || whichKey == '9' || whichKey == '0'){
 
    c++;
    if(c==1)
    {
      lcd.clear();
    }
    setLocked (true);
    lcd.setCursor(c, 0);
    lcd.print("*");
    delay(200);
  }
  
  if(whichKey == 'B')
  {
    if(degree = 90)
    {
      setLocked (true);
      servo.write(-90);
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print(" *** Locked ***");
      delay(2000);
      lcd.clear();
      c=0;   }
  } 
  if(whichKey == password [pozisyon]){
    pozisyon ++;
  }
  if(pozisyon == 4){
    setLocked (false);
    lcd.clear();
    lcd.setCursor(0, 0);
    for(int i=0;i<3;i++)
    {
    lcd.print(" Access Granted ");
    delay(300);
    lcd.clear();
    delay(200);
    }
    lcd.print(" Access Granted ");
    pozisyon=0;  }
  delay(100);}
void setLocked(int locked){
  if(locked){
    servo.write(0);
    }
    else{
      servo.write(degree); }
  }
