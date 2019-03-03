#include<dht.h>
dht DHT;
//  if  you require to change the pin number, Edit the pin with your arduino pin.
#define DHT11_PIN 3 
void setup() {
Serial.begin(9600);
} 
//Serial.println("Welcome to TechPonder Humidity and temperature Detector");    
void loop() {   // READ DATA 
int chk = DHT.read11(DHT11_PIN); 
//Serial.println(" Humidity " ); 
//Serial.println(DHT.humidity, 1); 
//Serial.println(" Temperature "); 
delay(500);
Serial.print(DHT.humidity, 1);
Serial.print(" ");
Serial.println(DHT.temperature, 1);
delay(2000); //sample every 1 minute (60,000 milliseconds)
}
