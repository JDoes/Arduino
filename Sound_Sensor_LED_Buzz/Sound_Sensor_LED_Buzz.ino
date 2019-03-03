/***************************************************
name:Rotary Encoder
function:you can see the angular displacement of the rotary encoder printed on Serial Monitor.
When the rotary encoder rotates clockwise, the angular displacement increases; when it does counterclockwise, the value decreases.
Press the switch on the rotary encoder, the value will return to zero.
********************************************************/
//Email:support@sunfounder.com
//website:www.sunfounder.com

const int ledPin = 13; //pin13 built-in led
const int soundPin = A0;  //sound sensor attach to A0
const int buzzer = 2;
void setup()
{
  pinMode(ledPin,OUTPUT);//set ledPin as OUTPUT
  Serial.begin(9600); //initialize the serial communication as 9600 bps
  pinMode(buzzer, OUTPUT);
 
}

void loop()
{
  int value = analogRead(soundPin); //read the value of sound sensor
  Serial.println(value);//print it
  if(value > 700)//if the vallue of sound sensor is greater than 700
  {
    digitalWrite(ledPin,HIGH); //turn on the led
    delay(500); //delay 200ms
    digitalWrite(ledPin, HIGH);
   delay(200);
   tone(buzzer, 600);
   digitalWrite(ledPin, LOW);
   delay(200);
   noTone(buzzer);
  }
  else //elae 
  {
    digitalWrite(ledPin,LOW); //turn off the led
  }
  delay(200);
}
