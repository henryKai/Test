#include <SPI.h>
#include <Mirf.h>
#include <nRF240L01.h>
#include <MirfHardwareSpiDriver.h>

int SoilMoisturePin = A0;

void setup(){
  Serial.begin(9600);
  
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setTADDR((byte *)"serv1");
  Mirf.payload = 10;
  Mirf.config();
  Serial.println("start");
}

byte Data[10];

void loop(){
  
  unsigned long time = millis();
  
  uint8_t voltage = analogRead(SoilMoisturePin) * (5.0/1024.0);
  Data[0] = voltage;
  //Serial.println(voltage);
  //Data[0] = voltage;
  //Serial.println(Data[0]);
  //memcpy(&Data[0],&voltage,1);
  Mirf.send(Data);
  Serial.println("Finished sending");
  delay(2000);
}
