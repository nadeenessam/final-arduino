#include <Servo.h>
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 6;
const int echoPin = 5;
#define Green 12
int sensorPin = 0;
int sensorVal = 0;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(9); // Defines on which pin is the servo motor attached
  pinMode(Green,OUTPUT);
  pinMode(sensorPin,INPUT);
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(10);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
 if (distance < 50){
  sensorVal = analogRead(sensorPin);
  if ( sensorVal < 400){
    digitalWrite(Green, HIGH);
    delay(50);
  } else{
    digitalWrite(Green, LOW);
  }
 } else{
    digitalWrite(Green, LOW);
  }
  }
   for(int i=15;i<=165;i++){  
  myServo.write(180-i);
  delay(10);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
 if (distance < 50){
  sensorVal = analogRead(sensorPin);
  if ( sensorVal < 400){
    digitalWrite(Green, HIGH);
    delay(50);
  } else{
    digitalWrite(Green, LOW);
  }
 }
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
