// Modified by John 2015 11 03
// MIT license
// DHT11 라이브러리로 DHT11.zip 설치 : by Choon Woo Kwon
//

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int FAN = 7;
int FAN2 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(FAN,OUTPUT);
  pinMode(FAN2,OUTPUT);
  
}
void loop() {
  delay(2000);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("C");

  if(isnan(h) || isnan(f)){
    Serial.println("fail dht");
    return;
  }
  if(((float)h)>=40){
    digitalWrite(FAN,HIGH);
    digitalWrite(FAN2,HIGH);
  }
  else if(((float)h)<=35){
     digitalWrite(FAN,LOW);
     digitalWrite(FAN2,LOW);
  }



}
