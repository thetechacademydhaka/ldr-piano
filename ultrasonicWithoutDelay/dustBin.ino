#define trigPin 3
#define echoPin 2

unsigned long inTime = 0;

//chnage delay here....
const long delayTime = 1000; 

void setup()
{
  
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);  
 pinMode(echoPin,INPUT);   

}

void loop(){
    
 unsigned long currTime = millis();
 if (currTime - inTime >= delayTime) {
    
    int duration,distance;  
    digitalWrite(trigPin, HIGH); 
    delay(500);
    digitalWrite(trigPin, LOW); 
    
    duration = pulseIn(echoPin,HIGH);  
    
    distance = (duration/2 )/29.1; 
  
    distance = map(distance, 5, 90, 0, 100);
    if(distance > 100)
      distance = 100;
    else if( distance < 0)
      distance = 0;

    inTime = currTime;
    
    Serial.print(String(distance));
  }
 
}
