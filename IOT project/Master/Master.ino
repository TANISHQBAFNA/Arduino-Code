#include <Wire.h>

int cm = 0;int flag0=0;int flag1=0;int sum=0;int flag2=0;int flag3=0;

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

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
	Wire.begin();
}

void loop()
{
 
  cm = 0.01723 * readUltrasonicDistance(A0,A0);
  if(cm<200){
    digitalWrite(13, LOW);
    flag0=0;
  Serial.println("1. Occupied");
  }
  else{
    digitalWrite(13, HIGH);                                        
    flag0=1;
    Serial.println("1. Vacant");
  }
  
 cm = 0.01723 * readUltrasonicDistance(A1,A1);
  if(cm<200){
    digitalWrite(12, LOW);
   Serial.println("2. Occupied");
    flag1=0;
  }
  else{
    digitalWrite(12, HIGH);
    Serial.println("2. Vacant");
    flag1=1;
 	}
   
  cm = 0.01723 * readUltrasonicDistance(A2,A2);
  if(cm<200){
        digitalWrite(11, LOW);
  Serial.println("3. Occupied");
    flag2=0;
  }
  else{
        digitalWrite(11, HIGH);
    Serial.println("3. Vacant");
    flag2=1;
 	}
  
   cm = 0.01723 * readUltrasonicDistance(A3,A3);
  if(cm<200){
            digitalWrite(10, LOW);
  Serial.println("4. Occupied");
    flag3=0;
  }
  else{
   digitalWrite(10, HIGH);
    Serial.println("4. Vacant");
    flag3=1;
 	}
  
  
  sum = flag0 + flag1 + flag2 + flag3;
  Serial.print("Vacant Spots :");
  Serial.println(sum);
  
  Wire.beginTransmission(A4);
  Wire.write(sum);              // sends one byte  
  Wire.endTransmission();
                            
}