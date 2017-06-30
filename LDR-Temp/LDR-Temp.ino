#include <Wire.h>                         // You can get the library though this link
                                          //  http://www.resistorpark.com/content/Arduino_Libraries/wire.zip
#define DEV_ID 0x90 >> 1                  

int gLed = 4;                             // Green led pin
int rLed = 2;                             // Red led pin
int LDR = A1;                             // LDR Analog pin

void setup() {
  Serial.begin(9600);
  
  pinMode(gLed, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(LDR,INPUT);

  Wire.begin();
  Wire.beginTransmission(DEV_ID);           // Connect to DS1621 (#0)
  Wire.write(0xAC);                         // Access Config
  Wire.write(0x02);                         // Set for continuous conversion
  Wire.beginTransmission(DEV_ID);           // Restart
  Wire.write(0xEE);                         // Start conversions
  Wire.endTransmission();
    
}

void readLDR ()
{
  long thresholdLDR = 200;                  // Threshold were the led will be triggered
  long LDRValue = 0;                        // Variable that will get the value of the pin A1

  LDRValue = analogRead(A1);                // We read A1
  
  Serial.print("LDR Value:");               // We print the value on the Serial Monitor
  Serial.println(LDRValue);  
     
  if(LDRValue <= thresholdLDR)              // If the value is below the threshold,we ligth the red led
  {                                         
    digitalWrite(rLed,HIGH);
  }
  else
  {
    digitalWrite(rLed,LOW);
  }
}

void readTemp()
{
  int8_t firstByte;                       //  Variables that will get the first and 
  int8_t secondByte;                      // second Byte of the temperature
  float tempValue = 0;                    // Variable that will get the temperature
  float thresholdTemp = 27;               // Threshold were the led will be triggered
  
  delay(1000);                            // Give time for measurement
  delay(1000); 
  Wire.beginTransmission(DEV_ID);
  Wire.write(0xAA);                       // Read temperature command
  Wire.endTransmission();
  Wire.requestFrom(DEV_ID, 2);            // Request two bytes from DS1621 (0.5 deg. resolution)
 
  firstByte = Wire.read();                // Get first byte
  secondByte = Wire.read();               // Get second byte

  tempValue = firstByte;
 
  if (secondByte)                           // If there is a 0.5 deg difference
  {
    tempValue += 0.5;
  }
  
 
  if (tempValue >= thresholdTemp)            // If the temperature is below the threshold,we ligth the green led
  {                                         
    digitalWrite(gLed, HIGH);
  }
  else 
  {
    digitalWrite(gLed, LOW);
  }
  Serial.print("Temperature:");             // We print the temperature on the Serial Monitor
  Serial.println(tempValue);
}

void loop() {
  readLDR();
  readTemp();
  delay(1000);  
}
