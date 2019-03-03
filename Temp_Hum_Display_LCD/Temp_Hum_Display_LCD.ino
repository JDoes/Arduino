#include<dht.h>
#include <LiquidCrystal.h>

// BS    E    D4 D5    D6 D7 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

dht DHT;
//  if  you require to change the pin number, Edit the pin with your arduino pin.
#define DHT11_PIN 3 
void setup() 
{ 
lcd.begin(16, 2);

Serial.begin(9600);
} 
//Serial.println("Welcome to TechPonder Humidity and temperature Detector");    
void loop() {   // READ DATA 
int chk = DHT.read11(DHT11_PIN); 
//Serial.println(" Humidity " ); 
//Serial.println(DHT.humidity, 1); 
//Serial.println(" Temperature "); 
Serial.print(DHT.humidity, 1);
Serial.print(" ");
Serial.println(DHT.temperature, 1); 

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Humid (%): ");
lcd.print(DHT.humidity, 1);
lcd.setCursor(0, 1); 
lcd.print("Temp (Cel): ");
lcd.print(DHT.temperature, 1);


//Serial.println(DHT.temperature, 1);
delay(60000); //sample every n minutes (60,000 milliseconds = 1 minute)
}
