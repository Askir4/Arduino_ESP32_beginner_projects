#define TRIGGER_SENT 2
const int trigPin = 6;
const int echoPin = 7;
  float duration; 
  float distanceCM;
  float distanceIn;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  
  // print distance
  Serial.print("Distance: ");
  Serial.print(distanceCM);
  Serial.print(" cm (");
  Serial.print(distanceIn);
  Serial.println(" in)");
  
  delay(1000);
}
