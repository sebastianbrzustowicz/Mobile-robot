#include <IRremote.h>                     // IR pin 11 
#define irPin 11                                
IRrecv irrecv(irPin);
decode_results results;  
int code;    


const unsigned int TRIG_PIN=13;           // echosonar 13 trigg 12 echo
const unsigned int ECHO_PIN=12;

#include <Servo.h>                        // servo pin 9
#define pinn 9;
int angle = 90;
bool directionchange = 0;
Servo myservo;                      


void setup() {
   Serial.begin(9600);
   irrecv.enableIRIn();                  // enable IR
   pinMode(TRIG_PIN, OUTPUT);            // echo
   pinMode(ECHO_PIN, INPUT);
   myservo.attach(9);                    // servo

   pinMode(2,OUTPUT);                    // H off
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);

   

}

void loop() {
  if (irrecv.decode(&results)) {                                                   // IR
      Serial.print("0x");
      Serial.println(results.value, HEX);
      delay(1);
      irrecv.resume();
      
      }
  if(results.value==0x40FF28D7)
  { results.value=4294967295;
    for(int i = 0; i<=200; i++){
   digitalWrite(2, LOW);                                                           // jazda do przodu
   digitalWrite(3, HIGH);
   digitalWrite(4, LOW);
   digitalWrite(5, HIGH);


   myservo.write(90);                                                             // servo
   
   
  digitalWrite(TRIG_PIN, LOW);                                                     // echo
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 if(distance<=20){break;} 
   }
   digitalWrite(2, LOW);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
  }
  if(results.value==0x40FFAA55)
  { results.value=4294967295;
    for(int i = 0; i<=80; i++){
   digitalWrite(2, LOW);                                                           // skręt w prawo
   digitalWrite(3, HIGH);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);

   if(i<=1){
   myservo.write(50);}                                                            // servo
   if(i==80){
   myservo.write(90);}  
    
   
  digitalWrite(TRIG_PIN, LOW);                                                     // echo
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 if(distance<=20){break;} 
   }
   digitalWrite(2, LOW);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
  }
  if(results.value==0x40FF2AD5)
  { results.value=4294967295;
    for(int i = 0; i<=80; i++){
   digitalWrite(2, LOW);                                                           // skręt w lewo
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, HIGH);

   if(i<=1){
   myservo.write(130);}                                                            // servo
   if(i==80){
   myservo.write(90);}  
    
   
  digitalWrite(TRIG_PIN, LOW);                                                     // echo
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 if(distance<=20){break;} 
   }
   digitalWrite(2, LOW);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
  }
  if(results.value==0x40FFE817)
  { results.value=4294967295;
    for(int i = 0; i<=200; i++){
   digitalWrite(2, HIGH);                                                           // jazda do tyłu
   digitalWrite(3, LOW);
   digitalWrite(4, HIGH);
   digitalWrite(5, LOW);


   myservo.write(90);                                                             // servo
   
   
  digitalWrite(TRIG_PIN, LOW);                                                     // echo
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 if(distance<=20){} 
   }
   digitalWrite(2, LOW);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
  }
}
