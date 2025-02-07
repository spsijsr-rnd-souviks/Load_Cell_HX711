#include <Arduino.h>
#include "HX711.h"

// Pin declaration with HX711
const int datpin1 = 2;
const int clkpin1 = 3;

long cal_factor = 103.6553;        // Put the calibration factor here

// Scale initialization
HX711 scale;

void setup() 
{
  Serial.begin(57600);
  scale.begin (datpin1, clkpin1);
    scale.set_scale(cal_factor);         
    scale.tare();
   Serial.println("Readings:");
}

void loop() 
{
  Serial.print("Weight on cell: ");
  Serial.print(scale.get_units(), 2);
  Serial.println(" gms");
  Serial.println();
  delay(2000);
}