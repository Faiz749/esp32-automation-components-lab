#define Flame_Digital_PIN 5
#define BUZZER_PIN 25
#define LED_PIN 27

unsigned long previousTime = 0;
const unsigned long intervalTime = 500;

void control_devices(int flame_digital_value){

  if(flame_digital_value == LOW){
    Serial.println("BUZZER: ON");
    Serial.println("LED: ON");
    digitalWrite(BUZZER_PIN,HIGH);
    digitalWrite(LED_PIN,HIGH);
  }
  else{
    Serial.println("BUZZER: OFF");
    Serial.println("LED: OFF");
    digitalWrite(BUZZER_PIN,LOW);
    digitalWrite(LED_PIN,LOW);
  }
}

void show_readings(int flame_digital_value){

  Serial.println("-----------------------------------");
  Serial.print("Status: ");
  if(flame_digital_value == LOW){
    Serial.println("FLAME DETECTED");
  }
  else{
    Serial.println("SAFE");
  }
  Serial.print("Digital Value: ");
  Serial.println(flame_digital_value);
  control_devices(flame_digital_value);
}

void setup(){

  Serial.begin(115200);
  pinMode(Flame_Digital_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
  Serial.println("Flame Alert Monitor Started");
  digitalWrite(BUZZER_PIN,LOW);
  digitalWrite(LED_PIN,LOW);

}

void loop(){

  unsigned long currentTime = millis();
  if(currentTime - previousTime >= intervalTime){
    previousTime = currentTime;
    int flame_digital_value = digitalRead(Flame_Digital_PIN);
    show_readings(flame_digital_value);
  }
}