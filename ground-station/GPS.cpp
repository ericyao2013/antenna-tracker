#include "GPS.h"
#include "Configuration.h"

#include <HardwareSerial.h>

#define MIN_NUMBER_OF_SATELLITES 6

GPS::GPS() {
  
  serialPort = &GPS_SERIAL;
  serialPort->begin(9600);
}

void GPS::tick() {
  while (serialPort->available()) {
    gpsPlus.encode(serialPort->read());
  }
  
  
  /*Serial.print(F("Satellites: "));
  Serial.print(gpsPlus.satellites.value());
  
  Serial.print(F("  Location: ")); 
  if (gpsPlus.location.isValid())
  {
    Serial.print(gpsPlus.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gpsPlus.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gpsPlus.date.isValid())
  {
    Serial.print(gpsPlus.date.month());
    Serial.print(F("/"));
    Serial.print(gpsPlus.date.day());
    Serial.print(F("/"));
    Serial.print(gpsPlus.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gpsPlus.time.isValid())
  {
    if (gpsPlus.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gpsPlus.time.hour());
    Serial.print(F(":"));
    if (gpsPlus.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gpsPlus.time.minute());
    Serial.print(F(":"));
    if (gpsPlus.time.second() < 10) Serial.print(F("0"));
    Serial.print(gpsPlus.time.second());
    Serial.print(F("."));
    if (gpsPlus.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gpsPlus.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();*/
}

boolean GPS::haveFix() {
  return gpsPlus.location.isValid() && gpsPlus.satellites.value() >= MIN_NUMBER_OF_SATELLITES;
}

byte GPS::numberOfSatellites() {
  return gpsPlus.satellites.value();
}

double GPS::distanceTo(double latitude, double longitude) {
  return TinyGPSPlus::distanceBetween(latitude, longitude, gpsPlus.location.lat(), gpsPlus.location.lng());
}

double GPS::latitude() {
  return gpsPlus.location.lat();
}

double GPS::longitude() {
  return gpsPlus.location.lng();
}

