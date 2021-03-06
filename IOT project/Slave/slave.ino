
#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int n=0;int cm=0;
int available=4;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
   digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {

  Wire.begin(A4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent);  
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("Car Parking");
  lcd.setCursor(4, 4);
  lcd.print("System");
  delay(100);
  lcd.clear();
 }

void receiveEvent(int howMany)
{ 
  int x = Wire.read();    // receive byte as an integer
  n=x;     // print the integer
}


void loop() 
{
  cm = 0.01723 * readUltrasonicDistance(7,7);
  
  if (cm < 200)
  { 
    delay(100);
    if(n > 0){
  lcd.setCursor(0, 0);
  lcd.print("Available : ");
  lcd.print(available);
  lcd.setCursor(0, 1);
  lcd.print("Vacant : ");
  lcd.print(n);
    }
     else
  {
    
    lcd.setCursor(2, 0);
    lcd.print("Parking Full");                                                  
           delay(100);

   lcd.clear();
  }
  }
  else{
    lcd.clear();
  }
 
}                  