#ifndef GPS_H
#define GPS_H

#include <Arduino.h>
#include <TinyGPS++.h>

#include "LocationProvider.h"

class SoftwareSerial;

class GPSLocationProvider: public LocationProvider {
public:
  GPSLocationProvider(int rxPin, int txPin);
  void tick();
  boolean isConnected();
  boolean haveFix();
  byte numberOfSatellites();
  double latitude();
  double longitude();
  long altitude();

private:
  SoftwareSerial *serialPort;
  TinyGPSPlus gpsPlus;
  boolean connected;
};

#endif


