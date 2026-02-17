#define TRIGGER_SENT 2
const int trigPin = 6;
const int echoPin = 7;
  float duration; 
  float distanceCM;
  float distanceIn;
//Warn LED
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // start with clean signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  
  // send trigger signal
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(TRIGGER_SENT, HIGH);
  delayMicroseconds(500);
  digitalWrite(TRIGGER_SENT, LOW);
  
  // read echo signal
  duration = pulseIn(echoPin, HIGH);
  
  // calculate distance
  // Calculate the distance in centimeters
  // Speed of sound is 0.034 cm/µs. Divide by 2 because the sound travels to the object and back.
  distanceCM = duration * 0.034 / 2;
  distanceIn = distanceCM * 0.393701;

  if (distanceCM < 4) {
    setColor(255, 0, 0); // Red
  } else if (distanceCM < 10) {
    setColor(0, 0, 255); // Blue
  } else if (distanceCM > 10) {
    setColor(0, 255, 0); // Green
  }

// print distance
  Serial.print("Distance: ");
  Serial.print(distanceCM);
  Serial.print(" cm (");
  Serial.print(distanceIn);
  Serial.println(" in)");
  
  delay(1000);
}
