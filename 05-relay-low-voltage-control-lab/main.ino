#define LED_PIN 2 
#define RELAY_PIN 18

int prevState = LOW;
bool Value_Entered = false;
unsigned long previousTime = 0;
unsigned long intervalTime = 200;

char Relay_Value();
void show_reading(char choice);
void compare_last_reading(int currentState);

void setup(){
  Serial.begin(115200);
  pinMode(RELAY_PIN,OUTPUT);
  digitalWrite(RELAY_PIN,HIGH);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("Relay Low-Voltage Control System");
  Serial.println("Press 1 to turn Relay ON");
  Serial.println("Press 0 to turn Relay OFF");
}

void loop(){
  unsigned long currentTime = millis();
  if(currentTime - previousTime >= intervalTime){
    previousTime = currentTime;
    char choice = Relay_Value();
    show_reading(choice);
  }
}

char Relay_Value(){
  if(Serial.available() > 0){
    Value_Entered = true;
    return Serial.read();
  }
  else{
    return '*';
  }
}

void show_reading(char choice){
  if(Value_Entered){
    if(choice == '1'){
      compare_last_reading(1);
    }
    else if(choice == '0'){
      compare_last_reading(0);
    }
    else if (choice != '*' && choice != '\n' && choice != '\r'){
      Serial.println("Enter a valid choice");
    }
    Value_Entered = false;
  }
}


void compare_last_reading(int currentState){
  if(currentState == prevState){
    Serial.println("Relay is already in the requested state");
    return;
  }
  prevState = currentState;
  if(prevState == HIGH){
    digitalWrite(RELAY_PIN,LOW);
    digitalWrite(LED_PIN,HIGH);
    Serial.println("Turning Relay ON");
    Serial.println("RELAY Status: ON");
    Serial.println("LED Status : ON");
  }
  else{
    digitalWrite(RELAY_PIN,HIGH);
    digitalWrite(LED_PIN,LOW);
    Serial.println("Turning Relay OFF");
    Serial.println("RELAY Status: OFF");
    Serial.println("LED Status : OFF");
  }
}