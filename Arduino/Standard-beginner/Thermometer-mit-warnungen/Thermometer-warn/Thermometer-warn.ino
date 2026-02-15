#include <DHT.h> 
#define toowarm 6
#define toocold 7
#define readerror 8
#define DHTTYPE DHT11
#define DHTPIN 13
 DHT dht(DHTPIN, DHTTYPE);
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

