#define REDLED 6
void setup() {
  // put your setup code here, to run once:
 pinMode(REDLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(REDLED, HIGH);
  delay(1000);
  digitalWrite(REDLED, LOW);
  delay(1000);

}
