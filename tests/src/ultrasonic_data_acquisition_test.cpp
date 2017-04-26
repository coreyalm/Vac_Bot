
  
  int client = 13; //The client pin
  int server = 11; //The server pin
  float pingTime; //time it takes for the server pin to send a response
  float speedOfObject;
  int targetDistance; //Distance between client and server pins
  const int delaySeconds = 10000;
 
 void setup(){
    Serial.begin(9600); //Sets the data rate in bits per second (baud) 
                        //for serial data transmission.
    pinMode(client,OUTPUT); //Sets trigPin as the client pin.
    pinMode(server, INPUT); //Sets echoPin as the server Pin. INPUT reacts to the environment. In this case it is reacting to the client pin's "high" state   
    
 }
 
void loop() {
 
 printf("\n Enter a value for the distance between pins: "); 
 int resultingDistance = scanf("%d", &targetDistance) * .0254;
 Serial.print("The distance is ");
 Serial.print(resultingDistance);
 Serial.print(" meters \n");
  
 digitalWrite(client,LOW); //Sets client pin as off
 delayMicroseconds(delaySeconds); //1 second delay for signal to settle
 digitalWrite(client, HIGH); //Sets client pin as on  
                             //Signal has been sent
 delayMicroseconds(delaySeconds);
 digitalWrite(client, LOW); //turns off client

 pingTime = pulseIn(server, HIGH); //server pin's reaction recorded in microseconds
 speedOfObject = (resultingDistance * .0254)/ pingTime * (1000000); 
 Serial.print("The speed of the object is: ");
 Serial.print(speedOfObject);
 Serial.print(" m/s");
 delay(delaySeconds);
}
