#include <SoftwareSerial.h>

const byte HC12RxdPin = 2;                  // Recieve Pin on HC12
const byte HC12TxdPin = 13;                  // Transmit Pin on HC12

SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC12.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("begiy begin");
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (HC12.available()) {
//    digitalWrite(13, HIGH);
//    delay(100);
//    digitalWrite(13, LOW);
    Serial.print("Read: ");
    Serial.print(HC12.read());
  }

  if (Serial.available()) {
    char a = Serial.read();
    Serial.print("Write: ");
    Serial.println(a);
    HC12.write(a);   
  }
}


