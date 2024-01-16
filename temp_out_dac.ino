

  #include <Wire.h>
#include <Adafruit_MCP4725.h>
#include "max6675.h"

int SO = 8;
int CS = 9;
int SCK1 =10;

MAX6675 thermocouple(SCK1, CS, SO);

Adafruit_MCP4725 dac;

// Set this value to 9, 8, 7, 6 or 5 to adjust the resolution
#define DAC_RESOLUTION    (8)
void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("MCP4725 Test");
  if (dac.begin(0x60))
  { Serial.println("MCP4725 fjfjf");
  }
  else
  { Serial.println("failed  ");
  }
}

void setMv(int mV)
{
  float dac_value = ((mV/1000.0)*4095.0) / 5;
  dac_value = (int)dac_value;
  dac.setVoltage(dac_value, false);
}
float temp;
void loop() {
  
//  Serial.println(dac_value);
  static unsigned long t =0;
  if(millis() - t>1000)
  {
    temp = thermocouple.readCelsius();
    Serial.print("t: ");
    Serial.println(thermocouple.readCelsius());
    t = millis();
  }
  setMv((int)temp * 10);
  }
