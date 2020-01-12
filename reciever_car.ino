#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
//Ip of the Host(Our Case esp8266-01 as server. Its the ip of the esp8266-01 as Access point)
const char* host = "192.168.4.1"; 
// defines pins numbers

const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

// defines variables
long duration;
int distance;
int led
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(4,OUTPUT);
Serial.begin(9600); // Starts the serial communication
  Serial.begin(115200);          //Baud Rate for Communication
  delay(10);                     //Baud rate prper initialization
  pinMode(13,INPUT);             //Pin D7 on NodeMcu Lua. Button to switch on and off the solenoid.
  WiFi.mode(WIFI_STA);           //NodeMcu esp12E in station mode
  WiFi.begin("ESP_D54736");      //Connect to this SSID. In our case esp-01 SSID.  

  while (WiFi.status() != WL_CONNECTED) {      //Wait for getting IP assigned by Access Point/ DHCP. 
  //Our case  esp-01 as Access point will assign IP to nodemcu esp12E.
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());             //Check out the Ip assigned by the esp12E
}

void loop() {

         if(digitalRead(13)==1){
           
                                     
              Serial.print("connecting to ");
              Serial.println(host);
              // Use WiFiClient class to create TCP connections
              WiFiClient client;
              const int httpPort = 80;
                if (!client.connect("192.168.4.1", httpPort)) {
                  Serial.println("connection failed");
                  return;
                  else{ // if connection established then on the ultrasonic sensor.
                    // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(2000);
 
                    
                  }
                   }                
            }
            if(distance<=800){    // if distance between two cars are less than 800 cm then buzzer will get on.
              digitalWrite(4,HIGH);
              
            }

}//End Loop
