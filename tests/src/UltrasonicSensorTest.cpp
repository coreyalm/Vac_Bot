#include <WProgram.h>
#define CLIENT 13 //The client pin
#define SERVER  11 //The server pin
float pingTime; //time it takes for the server pin to send a response
float speedOfObject;
int targetDistance = 6; //Distance between client and server pins
const int delaySeconds = 2000;

 void setup(){
    Serial.begin(9600); //Sets the data rate in bits per second (baud)
                        //for serial data transmission.
    pinMode(CLIENT,OUTPUT); //Sets trigPin as the client pin.
    pinMode(SERVER, INPUT); //Sets echoPin as the server Pin. INPUT reacts to the environment. In this case it is reacting to the client pin's "high" state   

 }

void loop(){

 Serial.print("\nThe distance is ");
 Serial.print(targetDistance);
 Serial.print(" meters \n");


 digitalWrite(CLIENT,LOW); //Sets client pin as off
 delayMicroseconds(delaySeconds); //1 second delay for signal to settle
 digitalWrite(CLIENT, HIGH); //Sets client pin as on  
                             //Signal has been sent
 delayMicroseconds(delaySeconds);
 digitalWrite(CLIENT, LOW); //turns off client

 
 pingTime = pulseIn(SERVER, HIGH); //server pin's reaction recorded in microseconds
 Serial.print("The pingTime of the object is: ");
 Serial.print(pingTime);
 Serial.print(" seconds \n");

 
 speedOfObject =(targetDistance*2)/pingTime*(1000000); ; 
  
 Serial.print("The speed of the object is: ");
 Serial.print(speedOfObject);
 Serial.print(" mph");
 delay(delaySeconds);

}

