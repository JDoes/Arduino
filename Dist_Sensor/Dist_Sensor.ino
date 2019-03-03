#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int dist;
int ledPin = 5;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);

}

void loop(){
  sensor();
  if (dist < 10) {
    digitalWrite(ledPin, HIGH);
    
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
 void sensor(){
  delay(50);
  unsigned int uS = sonar.ping();
  //Serial.print("Ping: ");
  //Serial.print(uS / US_ROUNDTRIP_CM);
  //Serial.println("cm");
  dist = uS / US_ROUNDTRIP_CM;
  Serial.println(dist);
  
 }


