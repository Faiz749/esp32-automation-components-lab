#define MQ2_ANALOG_PIN 34
#define LED_PIN 2

unsigned long startTime = 0;
const unsigned long warmupTime = 30000;
unsigned long previousTime = 0;
unsigned long intervalTime = 500;
bool sensorStatus = false;
int baseline_Threshold = 2200;
int warning_Threshold = 2500;
int danger_Threshold = 2600;

int average_value(){
  const int total_count = 15;
  long total = 0;
  for(int i=0;i<total_count;i++){
    total = total + analogRead(MQ2_ANALOG_PIN);
  }
  return total/total_count;
}

int analog_read(unsigned long currentTime){
  if(!sensorStatus && currentTime - startTime >= warmupTime){
    sensorStatus = true;
    Serial.println("Sensor Ready");
  }
  if(sensorStatus){
    return average_value();
  }
  return baseline_Threshold;
}

String get_sensor_status(int analog_value){
  if(sensorStatus){
    if(analog_value >= danger_Threshold){
      return "DANGER";
    }
    else if(analog_value >= warning_Threshold){
      return "WARNING";
    }
    else{
      return "SAFE";
    }
  }
  else{
    return "WARMING UP";
  }
}

void control_LED(String status){
  if(status == "WARNING"||status == "DANGER"){
    digitalWrite(LED_PIN,HIGH);
  }
  else{
    digitalWrite(LED_PIN,LOW);
  }
}

void show_readings(unsigned long currentTime,int analog_value,String status){
  if(sensorStatus){
    if(currentTime - previousTime >= intervalTime){
      previousTime = currentTime;
      Serial.println("-----------------------------------");
      Serial.print("Gas Value: ");
      Serial.println(analog_value);
      Serial.print("Baseline: ");
      Serial.println(baseline_Threshold);
      Serial.print("Warning Threshold: ");
      Serial.println(warning_Threshold);
      Serial.print("Danger Threshold: ");
      Serial.println(danger_Threshold);
      Serial.print("Status: ");
      Serial.println(status);
      Serial.print("LED: ");
      if(status == "WARNING" || status == "DANGER"){
        Serial.println("ON");
      }
      else{
        Serial.println("OFF");
      }
    }
  }
}

void setup(){

  Serial.begin(115200);
  pinMode(MQ2_ANALOG_PIN, INPUT);
  startTime = millis();
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN,LOW);
  Serial.println("Gas Sensor warming up");

}

void loop(){
  unsigned long currentTime = millis();
  int analog_value = analog_read(currentTime);
  String status = get_sensor_status(analog_value);
  control_LED(status);
  show_readings(currentTime,analog_value,status);
}