#define IR_PIN 19
#define FLAME_PIN 17
#define GAS_PIN 4
#define JOYSTICK_X_PIN 34
#define JOYSTICK_Y_PIN 35
#define JOYSTICK_BUTTON_PIN 13
#define LED_PIN 12
#define BUZZER_PIN 14

unsigned long startTime = 0;
unsigned long warmupTime = 30000;
bool sensorReady = false;
bool prev_button_state = false;
int prev_button_value = HIGH;
unsigned long previous_time = 0;
unsigned long intervalTime = 200;
unsigned long last_Button_press_time = 0;

void ready_sensors(void);
int get_gas_sensor_Reading(void);
String get_status(int IRvalue,int Flamevalue,int gasValue,String control_mode);
String JOYSTICK_mode(int JOYSTICK_button_value,unsigned long currentTime);
void control_devices(String Status,String JOYSTICK_POSITION,String control_mode);
String show_IRstatus(int IRvalue);
String show_Flame_status(int Flamevalue);
String show_gas_status(int gasValue);
void show_readings(String IR_Status,String Flame_Status,int gasValue,String gas_Status,String Status,int JOYSTICK_button_value,String JOYSTICK_POSITION);
String get_JOYSTICK_POSITION(void);


void setup(){

  Serial.begin(115200);
  ready_sensors();
  Serial.println("Multi-Sensor Safety Dashboard started");
}

void loop(){
  unsigned long currentTime = millis();
  int JOYSTICK_button_value = digitalRead(JOYSTICK_BUTTON_PIN);
  String control_mode = JOYSTICK_mode(JOYSTICK_button_value,currentTime);
  if(currentTime - previous_time >= intervalTime){
    previous_time = currentTime;
    int IRvalue = digitalRead(IR_PIN);
    String IR_Status = show_IRstatus(IRvalue);
    int Flamevalue = digitalRead(FLAME_PIN);
    String Flame_Status = show_Flame_status(Flamevalue);
    String JOYSTICK_POSITION = get_JOYSTICK_POSITION();
    int gasValue = get_gas_sensor_Reading();
    String gas_Status = show_gas_status(gasValue);
    String Status = get_status(IRvalue,Flamevalue,gasValue,control_mode);
    control_devices(Status,JOYSTICK_POSITION,control_mode);
    show_readings(IR_Status,Flame_Status,gasValue,gas_Status,Status,JOYSTICK_button_value,JOYSTICK_POSITION);
  }

}

void ready_sensors(void){

  pinMode(LED_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
  pinMode(IR_PIN,INPUT);
  pinMode(FLAME_PIN,INPUT);
  pinMode(GAS_PIN,INPUT);
  startTime = millis();
  pinMode(JOYSTICK_X_PIN,INPUT);
  pinMode(JOYSTICK_Y_PIN,INPUT);
  pinMode(JOYSTICK_BUTTON_PIN,INPUT_PULLUP);
  digitalWrite(LED_PIN,LOW);
  digitalWrite(BUZZER_PIN,LOW);

}


int get_gas_sensor_Reading(void){
  if(!sensorReady && millis() - startTime >= warmupTime){
    sensorReady = true;
  }
  if(sensorReady){
    return analogRead(GAS_PIN);
  }
  else{
    return -1;
  }
}

String get_status(int IRvalue,int Flamevalue,int gasValue,String control_mode){
  if(Flamevalue == 0){
    return "FLAME ALERT";
  }
  else if(gasValue >= 2800){
    return "GAS DANGER";
  }
  else if(gasValue >= 2600){
    return "GAS WARNING";
  }
  else if(IRvalue == 0){
    return "OBSTACLE DETECTED";
  }
  else if(control_mode == "MANUAL"){
    return "MANUAL INPUT";
  }
  else{
    return "NORMAL";
  }

}

String JOYSTICK_mode(int JOYSTICK_button_value,unsigned long currentTime){
  int debounce_time = 200;
  if(prev_button_value == HIGH && JOYSTICK_button_value == LOW){
    if(currentTime - last_Button_press_time >= debounce_time){
      last_Button_press_time = currentTime;
      prev_button_state = !prev_button_state;
    }
  }
  prev_button_value = JOYSTICK_button_value;
  if(prev_button_state){
    return "MANUAL";
  }
  else{
    return "AUTOMATIC";
  }
}

void control_devices(String Status, String JOYSTICK_POSITION, String control_mode) {

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  if (Status != "NORMAL" && Status != "MANUAL INPUT") {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  }

  else if (control_mode == "MANUAL") {
    if (JOYSTICK_POSITION == "LEFT") {
      digitalWrite(BUZZER_PIN, HIGH);
    }
    else if (JOYSTICK_POSITION == "RIGHT") {
      digitalWrite(LED_PIN, HIGH);
    }
  }
}

String show_IRstatus(int IRvalue){
  if(IRvalue == 0){
    return "Movement detected";
  }
  else{
    return "CLEAR";
  }
}

String show_Flame_status(int Flamevalue){
  if(Flamevalue == 0){
    return "FLAME DETECTED";
  }
  else{
    return "SAFE";
  }
}

String show_gas_status(int gasValue){
  if(gasValue >= 2800){
    return "GAS DANGER";
  }
  else if(gasValue >= 2600){
    return "WARNING";
  }
  else if (gasValue < 0){
    return "SENSORS WARMING UP";
  }
  else{ 
    return "SAFE";
  }
}

void show_readings(String IR_Status,String Flame_Status,int gasValue,String gas_Status,String Status,int JOYSTICK_button_value,String JOYSTICK_POSITION){
  Serial.println("===================================");
  Serial.println("MULTI-SENSOR SAFETY DASHBOARD");

  Serial.print("IR Status: ");
  Serial.println(IR_Status);

  Serial.print("Flame Status: ");
  Serial.println(Flame_Status);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  Serial.print("Gas Status: ");
  Serial.println(gas_Status);

  Serial.print("Button: ");
  if( JOYSTICK_button_value == LOW){
    Serial.println("PRESSED");
  }
  else{
    Serial.println("RELEASED");
  }

  Serial.print("Joystick Direction: ");
  Serial.println(JOYSTICK_POSITION);


  Serial.print("Overall Status: ");
  Serial.println(Status);

  Serial.println("===================================");
}

String get_JOYSTICK_POSITION(void){
  int xValue = analogRead(JOYSTICK_X_PIN);
  int yValue = analogRead(JOYSTICK_Y_PIN);
  if(xValue > 2800){
    return "UP";
  }
  else if(xValue < 1200){
    return "DOWN";
  }
  else if(yValue > 2800){
    return "RIGHT";
  }
  else if(yValue < 1200){
    return "LEFT";
  }
  else{
    return "CENTER";
  }
}

