#include<Keyboard.h>

int a = 180; 
int b = 240;
int c = 300;
int d = 350;
int e = 400;
int f = 500;
 
int x,y,z = 0;
void setup() {
  Keyboard.begin();
  Serial.begin(9600);
  pinMode(12,INPUT);
}

void loop() {
  
   x = analogRead(A0);
   y = analogRead(A1);
   z = analogRead(A2);
   
  Serial.println(x);
  if(digitalRead(5) == HIGH){ 

    //sensor 1
     if(x>=a && x<=b){
      Press('Q');
     }
     if(x>b && x<=c){
      Press('W');
     }
     if(x>c && x<=d){
      Press('E');
     }
     if(x>d && x<=e){
      Press('R');
     }
     if(x>e && x<=f){
      Press('T');
     }

     //sensor 2
     if(y>=a && y<=b){
      Press('Y');
     }
     if(y>b && y<=c){
      Press('U');
     }
     if(y>c && y<=d){
      Press('I');
     }
     if(y>d && y<=e){
      Press('O');
     }
     if(y>e && y<=f){
      Press('P');
     }

     //sensor 3
     if(z>=a && z<=b){
      Press('A');
     }
     if(z>b && z<=c){
      Press('S');
     }
     if(z>c && z<=d){
      Press('D');
     }
     if(z>d && z<=e){
      Press('F');
     }
     if(z>e && z<=f){
      Press('G');
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

