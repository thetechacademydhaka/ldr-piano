#include "Keyboard.h"

#define trigPin1 3
#define echoPin1 2

long duration1;
int distance1;

void setup() {
  Serial.begin(9600);   
  pinMode(trigPin1 ,OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(5,INPUT);
  pinMode(8,INPUT);
  
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {

 digitalWrite(trigPin1, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin1, LOW);

duration1 = pulseIn(echoPin1, HIGH);
distance1= duration1*0.034/2;

   if(digitalRead(5) == HIGH){
     if(distance1<=20){
      Keyboard.press(KEY_UP_ARROW);
      delay(100);
      Keyboard.releaseAll();
     }
     if(distance1<=40 && distance1>20){
      Keyboard.press(KEY_DOWN_ARROW);
      delay(100);
      Keyboard.releaseAll();
     }
     else
      Keyboard.releaseAll();
   }
   if(digitalRead(8) == HIGH && digitalRead(5) == HIGH){
     if(distance1<=20){
      Keyboard.press(KEY_LEFT_ARROW);
      delay(100);
      Keyboard.releaseAll();
     }
     if(distance1<=40 && distance1>20){
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(100);
      Keyboard.releaseAll();
     }
     else
      Keyboard.releaseAll();
   }
}
     
     
