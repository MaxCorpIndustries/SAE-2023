/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int Switch1 = 8;      
int Switch2 = 7;

int Switch1LED = 6;      
int Switch2LED = 5;

int ButtonState1 = 0 ;
int ButtonState2 = 0 ;

int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {

  pinMode(Switch1LED, OUTPUT);  
  pinMode(Switch2LED, OUTPUT);
  
  pinMode(Switch1, INPUT); 
  pinMode(Switch2, INPUT);
  
  Serial.begin(9600);
}

void loop() 
{

    sensorValue = analogRead(sensorPin);    
    Serial.println(sensorValue);    

    ButtonState1 = digitalRead(Switch1);
    ButtonState2 = digitalRead(Switch2);
  
  
    if (ButtonState1 == HIGH)
    {
    digitalWrite(Switch1LED, HIGH);
    Serial.println("Button 1 ON");  
    } 
    else 
    {
    digitalWrite(Switch1LED, LOW);
    Serial.println("Button 1 OFF");  
    }  
}
