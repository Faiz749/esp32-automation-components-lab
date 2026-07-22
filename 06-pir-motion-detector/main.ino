#define LED_PIN 2 
#define BUZZER_PIN 4 
#define PIR_PIN 18

const unsigned long warmupTime = 30000;
unsigned long startTime = 0;
bool sensorReady = false;
int lastSensorValue = -1;
unsigned long previousTime = 0;
const unsigned long intervalTime = 100;

String get_string(int sensorValue);
void control_devices(int sensorValue);
void  showReadings(int sensorValue,String Status);
void sensor_funciton(unsigned long currentTime);

void setup(){
  Serial.begin(115200);
  pinMode(LED_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
  digitalWrite(LED_PIN,LOW);
  digitalWrite(BUZZER_PIN,LOW);
  pinMode(PIR_PIN,INPUT);
  startTime = millis();
  Serial.println("PIR Security Alert Monitor");
  Serial.println("Getting System ready");
}
void loop(){
   unsigned long currentTime = millis();
  if(!sensorReady && currentTime - startTime >= warmupTime){
    sensorReady = true;
    Serial.println("System is ready");
  }
  if(sensorReady){
    sensor_funciton(currentTime);
  }
}
 

String get_string(int sensorValue){
  if(sensorValue == 1){
    return "MOTION DETECTED";
  }
  else{
    return "NO MOTION";
  }
}

void control_devices(int sensorValue){
   if(sensorValue == 1){
    digitalWrite(LED_PIN,HIGH);
    digitalWrite(BUZZER_PIN,HIGH);
  }
  else{
    digitalWrite(LED_PIN,LOW);
    digitalWrite(BUZZER_PIN,LOW);
  }
}

void showReadings(int sensorValue,String Status){
  Serial.println("-----------------------------------");
  Serial.print("Status: ");
  Serial.println(Status);
  Serial.print("PIR Value: ");
  Serial.println(sensorValue);
  if(Status == "NO MOTION"){
    Serial.println("LED: OFF");
    Serial.println("BUZZER: OFF");
  }
  else{
    Serial.println("LED: ON");
    Serial.println("BUZZER: ON");
  }
}

void sensor_funciton(unsigned long currentTime){
  if(currentTime - previousTime >= intervalTime){
    previousTime = currentTime;
    int sensorValue = digitalRead(PIR_PIN);
    String Status = get_string(sensorValue);
    if(sensorValue != lastSensorValue){
      showReadings(sensorValue,Status);
      control_devices(sensorValue);
      lastSensorValue = sensorValue;
      }
  }
}