/* LED Blink, Teensyduino Tutorial #1
   http://www.pjrc.com/teensy/tutorial.html
 
   This example code is in the public domain.
*/

// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.x / Teensy LC have the LED on pin 13
const int BSE_Switch = 17;
const int ledPin =  16;
int BSE_State = 0 ;


// the setup() method runs once, when the sketch starts

void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(BSE_Switch, INPUT);
  pinMode(ledPin, OUTPUT);
}

// the loop() methor runs over and over again,
// as long as the board has power

void loop() {
  BSE_State = digitalRead(BSE_Switch);
  
  
    if (BSE_State == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.println("HIGH");
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.println("LOW");
  }
               
}
 
