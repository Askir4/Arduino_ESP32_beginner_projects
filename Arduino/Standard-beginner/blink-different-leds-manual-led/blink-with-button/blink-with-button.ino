#define WHITELED 5
#define REDLED 6
#define GREENLED 7
#define BLUELED 8
#define YELLOWLED 9


void setup() {
    pinMode(WHITELED, OUTPUT);
    pinMode(REDLED, OUTPUT);
    pinMode(GREENLED, OUTPUT);
    pinMode(BLUELED, OUTPUT);
    pinMode(YELLOWLED, OUTPUT);
    digitalWrite(WHITELED, HIGH);
}

void loop (){
 digitalWrite(REDLED, HIGH);
 delay(2000);
 digitalWrite(REDLED, LOW);
 delay(10);
 digitalWrite(GREENLED, HIGH);
 delay(2000);
 digitalWrite(GREENLED, LOW);
 delay(10);
 digitalWrite(BLUELED, HIGH);
 delay(2000);
 digitalWrite(BLUELED, LOW); 
 delay(10);   
 digitalWrite(YELLOWLED, HIGH);    
 delay(2000);    
 digitalWrite(YELLOWLED, LOW);    
 delay(10);    
}