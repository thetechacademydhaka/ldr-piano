#include<Keyboard.h>

int a = 150; 
int b = 200;

int x,y,z = 0;
void setup() {
  Keyboard.begin();
  Serial.begin(9600);
  pinMode(12,INPUT);
}

void loop() {
  
   x = analogRead(A0);
  if(digitalRead(12) == HIGH){ 
     if(x>=a && x<=b){
      Press('Q');
     }
     else
      Keyboard.releaseAll();
  }
   delay(2);
 
}

void Press(char letter){

  Keyboard.press(letter);
  delay(100);
  Keyboard.releaseAll();
  
}

