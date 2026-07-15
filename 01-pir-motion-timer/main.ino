#define PIR_PIN 25 
#define LED_PIN 2

unsigned long lastMotionTime = 0;
unsigned long intervalTime = 5000; 
int prev_state = LOW;
int current_state = LOW;

void setup(){
  Serial.begin(115200);
  pinMode(PIR_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("Sensor warming up");
  delay(30000);
  Serial.println("Sensor ready");
}

void loop(){
  int motion_reading = digitalRead(PIR_PIN);
  unsigned long currentTime = millis();
  
  if(motion_reading == LOW){
    lastMotionTime = currentTime;
    digitalWrite(LED_PIN,HIGH);
    current_state = HIGH;
  } 

  if(currentTime - lastMotionTime >= intervalTime){
    digitalWrite(LED_PIN,LOW);
    current_state = LOW;

  }
  if(current_state == LOW && prev_state == HIGH){
    Serial.println("No Motion Detected");
    Serial.println("LED turned OFF");
  }  
  else if(current_state == HIGH && prev_state == LOW){
    Serial.println("Motion Detected");
    Serial.println("LED turned ON");
  }
  prev_state = current_state;
}