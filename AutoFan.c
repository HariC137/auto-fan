#include <LiquidCrystal.h>
//#include <lcd_Key.h>
void setup() {
//  // put your setup code here, to run once:
//  //define keycode for lcd push button
//#define None 0
//#define Select 1
//#define Left 2
//#define Up 3
//#define Down 4
//#define Right 5
//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
//lcd_Key keypad;
//define pin name
//#define diy_pwm A2
#define pwm 3
#define dir 2
#define pot A1
pinMode(4,INPUT);
//Serial.begin(115200);
Serial.begin(9600);
}

  
void loop(){
int localKey;                         //initialization
int pwm_value;
int reading = 0;
int prev_reading = 0;
int output = 0;
//lcd.setCursor(0,0);                ////lcd display on beginning
//lcd.print("PWM:");
//lcd.print(output);
//lcd.setCursor(0,1);
//lcd.print("DIR:");
//lcd.print(digitalRead(dir));
//while(1){
//localKey = keypad.getKey();
//if(localKey==Left){
int var = digitalRead(4);
Serial.print("var:");
Serial.println(var);
digitalWrite(dir,var);  //toggle and display motor direction if LEFT button pressed
//lcd.setCursor(0,1);
//lcd.print("DIR:");
//lcd.print(digitalRead(dir));
//delay(200);
//}
reading = 0;               //get average five consecutive analog readings from A1 pin (pot)
//for(int i =0;i<5;i++)
reading = analogRead(pot);
int PWM = map(reading,0,1023,0,255);
Serial.print("pot:");
//reading/=5;
//output=reading*0.2493;//convert from 10 bit to 8 bit, 0.2493 = 255/1023

Serial.println(reading);
Serial.print("PWM:");
Serial.println(PWM);
Serial.println();

//if(reading!=prev_reading){  //update //lcd data if only the reading changes to prevent reading on
//                            ////lcd blinking
////lcd.print(" ");
////lcd.setCursor(0,0);
////lcd.print("PWM:");
////lcd.print(output);
//prev_reading = reading;
//}
analogWrite(pwm,PWM);
//delay(1000);
}
