//This project is a smart speedometer that will be mounter in my car.
//Please note that this project is for educational purposes only.
//It is not meant to be used as a legal speedometer.
#include <Wire.h> // For I2C communication
#include <TinyGPSPlus.h> // For GPS data parsing
#include <Adafruit_GFX.h> // Graphics library
//#incldue //placeholder for screen drivers
#include <HardwareSerial.h> // Allows using multiple serial ports

//Oled display setup (placeholder too)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//GPS Module setup (placeholder too)
TinyGPSPlus gps; //TinyGPSPlus object handels parsing of GPS data
#define gpsSerial Serial2

