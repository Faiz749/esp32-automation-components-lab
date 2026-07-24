#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
void showReadings(float acceleration_x,float acceleration_y,float acceleration_z,float gyro_x,float gyro_y,float gyro_z,String orientation);
String get_orientation(float xValue, float yValue);
unsigned long previousTime = 0;
unsigned long intervalTime = 200;

void setup(){
  Serial.begin(115200);
  if(!mpu.begin()){
    Serial.println("MPU6050 sensor not found");
    while(true){
      delay(100);
    }
  }
  Serial.println("MPU6050 Tilt Monitor started");
}

void loop(){
  unsigned long currentTime = millis();
  if(currentTime - previousTime >= intervalTime){
    previousTime = currentTime;
    sensors_event_t acceleration;
    sensors_event_t gyro;
    sensors_event_t temperature;
    mpu.getEvent(&acceleration, &gyro, &temperature);
    String orientation = get_orientation(acceleration.acceleration.x,acceleration.acceleration.y);
    showReadings(acceleration.acceleration.x,acceleration.acceleration.y,acceleration.acceleration.z,gyro.gyro.x,gyro.gyro.y,gyro.gyro.z,orientation);
  }
}

void showReadings(float acceleration_x,float acceleration_y,float acceleration_z,float gyro_x,float gyro_y,float gyro_z,String orientation){
  Serial.println("-----------------------------------");

  Serial.print("Acceleration X: ");
  Serial.println(acceleration_x);

  Serial.print("Acceleration Y: ");
  Serial.println(acceleration_y);

  Serial.print("Acceleration Z: ");
  Serial.println(acceleration_z);

  Serial.print("Gyroscope X: ");
  Serial.println(gyro_x);

  Serial.print("Gyroscope Y: ");
  Serial.println(gyro_y);

  Serial.print("Gyroscope Z: ");
  Serial.println(gyro_z);

  Serial.print("Orientation: ");
  Serial.println(orientation);

}

String get_orientation(float xValue, float yValue){
  if (xValue > 4.0){
    return "TILTED RIGHT";
  }
  else if (xValue < -4.0){
    return "TILTED LEFT";
  }
  else if (yValue > 4.0){
    return "TILTED FORWARD";
  }
  else if (yValue < -4.0){
    return "TILTED BACKWARD";
  }
  else{
    return "LEVEL";
  }
}