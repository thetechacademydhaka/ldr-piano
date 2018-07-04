#include<Keyboard.h>

#define trigPin1 3
#define echoPin1 2

#define trigPin2 6
#define echoPin2 4

#define trigPin3 8
#define echoPin3 7

long duration1,duration2,duration3;
int x,y,z;

int a = 5;
int b = 10;
int c = 15;
int d = 20;
int e = 30;
int f = 40;

void setup() {
  
  Keyboard.begin();
  Serial.begin(9600);   
  pinMode(trigPin1 ,OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2 ,OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3 ,OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(5,INPUT);
  Serial.begin(9600);
}

void loop() {

   distance1();
   delay(2);
   distance2();
   delay(2);
   distance3(); 
       
   if(digitalRead(5) == HIGH){ 

    //sensor 1
     if(x>=a&& x<=b){
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
   
}// end of loop

void distance1(){
 digitalWrite(trigPin1, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin1, LOW);

 duration1 = pulseIn(echoPin1, HIGH);
 x= duration1*0.034/2;
 if(x>=120) x=120;
 Serial.println(x);
}

void distance2(){
  
 digitalWrite(trigPin2, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin2, LOW);

 duration2 = pulseIn(echoPin2, HIGH);
 y= duration2*0.034/2;
 if(y>=120) y=120;
 Serial.println(x);
}

void distance3(){
  
 digitalWrite(trigPin3, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin3, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin3, LOW);

 duration3 = pulseIn(echoPin3, HIGH);
 z= duration3*0.034/2;
 if(z>=120) z=120;
 Serial.println(z);
}

void Press(char letter){

  Keyboard.press(letter);
  delay(100);
  Keyboard.releaseAll();
  
}

