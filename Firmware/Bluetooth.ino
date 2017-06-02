#include <SoftwareSerial.h>

#define AT_MODE 0

SoftwareSerial BTSerial(10, 11); // (RX, TX) CONNECT BT TX PIN TO ARDUINO 10 PIN | CONNECT BT RX PIN TO ARDUINO 11 PIN

void setup() 
{
  Serial.begin(9600); // Serial is default serial on Arduino
  
  #if (AT_MODE == 1)
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH); 
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
  #else
  Serial.println("Enter Communicate mode");
  BTSerial.begin(115200);  // HC-05 default speed in AT command more
  #endif
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
