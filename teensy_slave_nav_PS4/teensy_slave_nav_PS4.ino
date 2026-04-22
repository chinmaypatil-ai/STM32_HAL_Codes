#include <Wire.h>
#define SLAVE_ADDRESS 0x08
int8_t navigation[3];  // Vx, Vy, w
float V1, V2, V3;
float r = 1;  // Wheel radius factor


void onReceive(int bytesReceived) {
  for (int i = 0; i < bytesReceived ; i++) {
    navigation[i] = Wire2.read();
  }
}

void setup() {
  Serial.begin(115200);
  Wire2.begin(8);  //For ESP32
  Wire2.onReceive(onReceive);

}

void loop() {

  int8_t Vx = navigation[0];
  int8_t Vy = navigation[1];
  int8_t w = navigation[2];

  if(abs(Vx)< 10) Vx = 0;
  if(abs(Vy)< 10) Vy = 0;
  


  Serial.print(Vx);
  Serial.print("\t");
  Serial.print(Vy);
  Serial.print("\t");
  Serial.print(w);

  Serial.println("\t");

}
