#include<Keyboard.h>

int a; 
int b;
int c;
int d;
int e;
int f;

int x,y,z,avg = 0;

void setup() {
  
  Keyboard.begin();
  Serial.begin(9600);
  pinMode(6,INPUT);
  calibration();
}

void loop() {
  
   x = analogRead(A0);
   y = analogRead(A1);
   z = analogRead(A2);
    
   if(digitalRead(12) == HIGH){ 
    //sensor 1
    Serial.println("hi");
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

void calibration(){
  x = analogRead(A0);
  y = analogRead(A1);
  z = analogRead(A2);
  avg = (x+y+z)/3;
  a = avg+50;
  b = a+50;
  c = b+50;
  d = c+50;
  e = d+50;
  f = e+50;
  
   Serial.print(a);
   Serial.print("  ");
   Serial.print(b);
   Serial.print("   ");
   Serial.print(c);
   Serial.print("   ");
   Serial.print(d);
   Serial.print("   ");
   Serial.print(e);
   Serial.print("   ");
   Serial.println(f);
}

void PRINTsensors(){
   Serial.print(digitalRead(12));
   Serial.print("   ");
   Serial.print(x);
   Serial.print("  ");
   Serial.print(y);
   Serial.print("   ");
   Serial.println(z);
}

void printRange(){
   Serial.print(a);
   Serial.print("  ");
   Serial.print(b);
   Serial.print("   ");
   Serial.print(c);
   Serial.print("   ");
   Serial.print(d);
   Serial.print("   ");
   Serial.print(e);
   Serial.print("   ");
   Serial.println(f);
}


