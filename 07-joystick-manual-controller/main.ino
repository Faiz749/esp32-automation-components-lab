#define JOYSTICK_X_PIN 35
#define JOYSTICK_Y_PIN 34
#define JOYSTICK_BUTTON_PIN 27
#define LEFT_LED_PIN 21
#define RIGHT_LED_PIN 2
#define UP_LED_PIN 4
#define DOWN_LED_PIN 5

unsigned long previousTime = 0;
unsigned long intervalTime = 1000;

void control_pins();
String get_direction(int Xvalue, int Yvalue);
void control_LED(String direction,int buttonValue);
void show_readings(int Xvalue,int Yvalue,String direction,int buttonValue);

void setup(){
  Serial.begin(115200);
  control_pins();
  Serial.println("Joystick Manual Controller started");
  Serial.println("System Ready");
}

void loop(){
  unsigned long currentTime = millis();
  if(currentTime - previousTime >= intervalTime){
    previousTime = currentTime;
    int Xvalue = analogRead(JOYSTICK_X_PIN);
    int Yvalue = analogRead(JOYSTICK_Y_PIN);
    int buttonValue = digitalRead(JOYSTICK_BUTTON_PIN);
    String direction = get_direction(Xvalue,Yvalue);
    control_LED(direction,buttonValue);
    show_readings(Xvalue,Yvalue,direction,buttonValue);
  }
}

void control_pins(){
  pinMode(LEFT_LED_PIN,OUTPUT);
  pinMode(RIGHT_LED_PIN,OUTPUT);
  pinMode(UP_LED_PIN,OUTPUT);
  pinMode(DOWN_LED_PIN,OUTPUT);
  pinMode(JOYSTICK_X_PIN,INPUT);
  pinMode(JOYSTICK_Y_PIN,INPUT);
  pinMode(JOYSTICK_BUTTON_PIN,INPUT_PULLUP);
  digitalWrite(LEFT_LED_PIN,LOW);
  digitalWrite(RIGHT_LED_PIN,LOW);
  digitalWrite(UP_LED_PIN,LOW);
  digitalWrite(DOWN_LED_PIN,LOW);
}

String get_direction(int xValue, int yValue){
  if (yValue < 1200){
    return "LEFT";
  }
  else if (yValue > 2800){
    return "RIGHT";
  }
  else if (xValue > 2800){
    return "UP";
  }
  else if (xValue < 1200)
  {
    return "DOWN";
  }
  else
  {
    return "CENTER";
  }
}

void control_LED(String direction,int buttonValue){
  digitalWrite(LEFT_LED_PIN, LOW);
  digitalWrite(RIGHT_LED_PIN, LOW);
  digitalWrite(UP_LED_PIN, LOW);
  digitalWrite(DOWN_LED_PIN, LOW);

  if(buttonValue == LOW){
    digitalWrite(LEFT_LED_PIN,HIGH);
    digitalWrite(RIGHT_LED_PIN,HIGH);
    digitalWrite(UP_LED_PIN,HIGH);
    digitalWrite(DOWN_LED_PIN,HIGH);
  }
  else{
    if(direction == "LEFT"){
      digitalWrite(LEFT_LED_PIN,HIGH);
    }
    else if(direction == "RIGHT"){
      digitalWrite(RIGHT_LED_PIN,HIGH);
    }
    else if(direction == "UP"){
      digitalWrite(UP_LED_PIN,HIGH);
    }
    else if(direction == "DOWN"){
      digitalWrite(DOWN_LED_PIN,HIGH);
    }
  }
}

void show_readings(int Xvalue,int Yvalue,String direction,int buttonValue){
  Serial.println("-----------------------------------");
  Serial.print("X Value: ");
  Serial.println(Xvalue);
  Serial.print("Y Value: ");
  Serial.println(Yvalue);
  Serial.print("Direction: ");
  Serial.println(direction);
  Serial.print("Button: ");
  if(buttonValue == LOW){
    Serial.println("PRESSED");
  }
  else{
    Serial.println("RELEASED");
  }
}


