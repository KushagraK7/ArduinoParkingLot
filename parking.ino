/*ParkingL02.pde
Arduining.com 08 JUL 2012
Code used in the production of the Youtube material.
*/

#include <Servo.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
Servo myservo;  // create servo object to control a servo

#define ServoM    7        //Connected to the servo motor.
#define Exit      9         //Pin connected to the EXIT button.
#define In        8         //Pin connected to the IN button.
#define Pwr  6
#define BarLow    90      //Low position of the barrier.
#define BarUp     177        //Up position of the barrier.
#define CAPACITY  7         //Capacity of the parking lot.






void setup(){
  myservo.attach(ServoM);          // attaches the servo.
  lcd.begin(16,2);
  lcd.print("Space left");
  pinMode(Pwr, OUTPUT);
  pinMode(Exit, INPUT);           // set "EXIT" button pin to input
  pinMode(In, INPUT);             // set "IN" button pin to input
  digitalWrite(Pwr, HIGH);
  digitalWrite(Exit, HIGH);       // Connect Pull-Up resistor.
  digitalWrite(In, HIGH);         // Connect Pull-Up resistor.
  myservo.write(BarLow);          //Barrier in the low position
//  delay(1000);
}

int  Available= 7;                    // Number of places available.

//================================================================
void loop(){
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Space left");
lcd.setCursor(0,1);  
lcd.print(Available);
if(digitalRead(In)==0)
{
  if(Available != 0){
    Available--;
    myservo.write(BarUp);
    delay(3000);
    myservo.write(BarLow);
    }
  }
if(digitalRead(Exit)==0)
{
  if(Available != CAPACITY){
    Available++;
    myservo.write(BarUp);
    delay(3000);
    myservo.write(BarLow);
    }
  }
  if(Available == 0){
    
    lcd.setCursor(1,0);
    lcd.print("Lot full!");
  }
delay(20);
}



