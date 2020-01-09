

//Car MP3 remote: left right center = - + eq = FFE01F FFA857 FF906F
//IR Codes for "Sony Personal Audio System RMT-CCS15"
//Up (up key) 2426
//Down (down key)  6426

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>
 
// Include Arduino Servo Library
#include <Servo.h>
 
// Define Sensor Pin
const int RECV_PIN = 4;
 
// Define Servo Pin
const int SERVO_PIN = 6;
 
// Define Variable for Servo position
// Start at 180 Degrees (Closed Position)
int pos = 180;         
 
// Define variable to store last code received
unsigned long lastCode; 
 
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;
 
// Create servo object
Servo myservo;          
 
void setup()
{
  // Start the receiver
  irrecv.enableIRIn();
   
  // Attach the servo
  myservo.attach(SERVO_PIN); 
 
  // Start with Servo in Center
  myservo.write(pos); 
}
 
void loop() {
if(irrecv.decode(&results)) //this checks to see if a code has been received
{
 
    if(results.value == 0xFFFFFFFF)   
    {
       // If Repeat then use last code received
       results.value = lastCode;        
    }
 
    if(results.value == 0x6426)    
    {
        // Minus - Button Pressed
        lastCode = results.value;
        // Move down     
        pos = 180; 
        // Prevent position above 180
        if(pos > 180){pos = 180;}                     
        myservo.write(pos);      
    }
      
    if(results.value == 0x2426)     
    {
       // Plus + Button Pressed
       lastCode = results.value;
       // Open  
       pos = 40; 
       // Prevent position below 40
       if(pos < 40){pos = 40;}                   
       myservo.write(pos);     
    }
 
   if(results.value == 0xFF906F)     
    {
       // Eq   Button Pressed
       lastCode = results.value;
       // Center  
       pos = 90;          
       myservo.write(pos);     
    }
 
    // Add delay to prevent false readings
    delay(30); 
    //receive the next value  
    irrecv.resume(); 
}
    
}
