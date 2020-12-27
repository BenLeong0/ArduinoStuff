const int buttonPin = 12;
int buttonState = 0;

void setup() {
  for (int i=2; i<=9; i++) {
    pinMode(i,OUTPUT);
//    if (i<=4) {
//      digitalWrite(i,HIGH);
//    }
  }
}

int f(int n) {
  return (n-2)%8+2;
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    for (int i=2;i<=9;i++) {
      delay(50);
      digitalWrite(f(i),HIGH);
      digitalWrite(f(i-3),LOW);
    }
    for (int i=7;i<=9;i++) {
      delay(50);
      digitalWrite(i,LOW);
    }
  }
}
