#define REDLED 7
#define BLUELED 1
void setup() {
  // put your setup code here, to run once:
pinMode(1, OUTPUT);
pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(BLUELED, HIGH);
delay(1000);
digitalWrite(BLUELED, LOW);
delay(10);
digitalWrite(REDLED, HIGH);
delay(1000);
digitalWrite(REDLED, LOW);
delay(10);
}
