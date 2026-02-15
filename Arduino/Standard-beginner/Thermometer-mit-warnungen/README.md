## About

This is the first project-like build I did with the Arduino. It uses the DHT11 sensor to measure the temperature and humidity and shows the values on the Serial Monitor. It also has three LEDs that indicate if the temperature is too high, too low, or if the sensor is not working.

## Nedded components

 - DHT11 sensor
 - 3 LEDs
 - 3 resistors
 - Breadboard
 - Jumper wires
 - Arduino UNO R3

## Schematics

The Schematics will follow later since I need to figure out how to create them first. (I will update this section as soon as I figure out how to do it.)

## Code

The code can be found in the "Thermometer-warn.ino" file.

It is very simple since it just uses the DHT libary for the DHT11 sensor and checks if the temperature is too high, too low, or if the sensor is not working.

```
#include <DHT.h> 
#define toowarm 6
#define toocold 7
#define readerror 8
#define DHTTYPE DHT11
#define DHTPIN 13
 DHT dht(DHTPIN, DHTTYPE);
```
In this section the libary is included. The pins for the LEDs and the sensor are also defined.


```
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  delay(100);

  //test leds
  digitalWrite(toowarm, HIGH);
  digitalWrite(toocold, HIGH);
  digitalWrite(readerror, HIGH);
  delay(2000);
  digitalWrite(toowarm, LOW);
  digitalWrite(toocold, LOW);
  digitalWrite(readerror, LOW);

  }
```
Here is the setup definded. The serial communication is initialized, the DHT sensor is started, and the LEDs are set to output mode for 2 seconds to test if they are working.

```
void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();

 
 if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    digitalWrite(readerror, HIGH);
    delay(1000);
    digitalWrite(readerror, LOW);
    delay(1000);
    return;
  }

  else {
  Serial.print("Current humidity=");
  Serial.print(h);
  Serial.print("%  Current temperature=");
  Serial.print(t);
  Serial.println("°C");
  
  // LEDs zurücksetzen
  digitalWrite(readerror, LOW);
  delay(3000);

  }

  if (t > 25.0) {
    digitalWrite(toowarm, HIGH);
    delay(1000);
    digitalWrite(toowarm, LOW);
  }
  else if (t < 18.0) {
    digitalWrite(toocold, HIGH);
    delay(1000);
    digitalWrite(toocold, LOW);
  }
}
```
Here is the main function. It reads the temperature and humidity from the DHT sensor and shows the values on the Serial Monitor. It also checks if the temperature is too high, too low, or if the sensor is not working.

If the temperature is too high, the toowarm LED is turned on for 1 second and then turned off. If the temperature is too low, the toocold LED is turned on for 1 second and then turned off. If the sensor is not working, the readerror LED is turned on for 1 second and then turned off.

Since it is my first project-like build, it is not very complex. But I am a bit proud it actually works, since I am a complete beginner.