#include <ESP32Servo.h>

#define SERVO_PIN 18
#define POT_PIN 34

unsigned long previousTime = 0;
const unsigned long intervalTime = 500;

Servo gateServo;

void show_readings(int POT_value,int angle);
void gate_position(int angle);

void setup(){
  Serial.begin(115200);
  gateServo.attach(SERVO_PIN);
  pinMode(POT_PIN,INPUT);
  gateServo.write(90);
  Serial.println("Potentiometer-Controlled Servo Safety Gate");
  Serial.println("System Ready");

}

void loop(){
  unsigned long currentTime = millis();
  if(currentTime - previousTime >= intervalTime ){
    previousTime= currentTime;
    int POT_value = analogRead(POT_PIN);
    int angle = map(POT_value,0,4095,10,170);
    gateServo.write(angle);
    show_readings(POT_value,angle);
  }
}

void show_readings(int POT_value,int angle){
  Serial.println("-----------------------------------");
  Serial.print("Potentiometer Value: ");
  Serial.println(POT_value);
  Serial.print("Servo Angle: ");
  Serial.println(angle);
  Serial.print("Gate Position: ");
  gate_position(angle);
  Serial.println("-----------------------------------");
}

void gate_position(int angle){
  if(angle <= 60){
    Serial.println("CLOSED");
  }
  else if(angle <= 120){
    Serial.println("HALF OPEN");
  }
  else{
    Serial.println("OPEN");
  }
}