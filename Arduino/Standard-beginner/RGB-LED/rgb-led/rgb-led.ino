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
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  setColor(255, 0, 0);   // Rot
  delay(1000);
  setColor(0, 255, 0);   // Grün
  delay(1000);
  setColor(0, 0, 255);   // Blau
  delay(1000);
}
