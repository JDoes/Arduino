#define TRIGGER_PIN 12
#define ECHO_PIN 11
int buzzer = 3;
int ledPin = 5;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode(TRIGGER_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(buzzer, OUTPUT);
}

void loop(){
int duration, distance;
digitalWrite(TRIGGER_PIN, HIGH);
delayMicroseconds(1000);
digitalWrite(TRIGGER_PIN, LOW);
duration = pulseIn(ECHO_PIN, HIGH);
distance = (duration/2) / 29.1;
if (distance >= 80 || distance <= 0){
Serial.println("no object detected");
digitalWrite(buzzer, LOW);}
else{
Serial.println("object detected");
tone(buzzer, 300);
digitalWrite(ledPin, HIGH);
delay(200);
tone(buzzer, 400);
digitalWrite(ledPin, LOW);
delay(200);
tone(buzzer, 500);
digitalWrite(ledPin, HIGH);
delay(200);
tone(buzzer, 600);
digitalWrite(ledPin, LOW);
delay(200);
noTone(buzzer);
}
delay(200);
}



