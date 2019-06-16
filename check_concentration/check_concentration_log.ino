#include <Time.h>

int numReadings = 500;
int readingCounter = 0;
int cnt = 0;
int seconds = 0;
int val;

double duration, distance;
const int trigPin = 7;
const int echoPin = A0;
const int buttonPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  cnt = 0;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  val = digitalRead(buttonPin);
  
  duration = pulseIn(echoPin, HIGH);
  distance = ((duration*340)/10000)/2;
  if (distance < 100) {
      //Serial.println(millis()/1000);
      Serial.println(distance);
  }
  delay(100);
  if(val == 0) {
    cnt++;
    Serial.println(cnt);
    delay(500);
  }
  else{
    Serial.println(0);
    delay(200);
  }
}
