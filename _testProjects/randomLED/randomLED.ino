const int buttonPin = 12;
const int buzzerPin = 11;
int buttonState = 0;
bool pressed = false;
int result;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
  for (int i=2; i<=9; i++) {
    pinMode(i,OUTPUT);
  }
}

void turnOffAll() {
  for (int i=2; i<=9; i++) {
    digitalWrite(i,LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && !pressed) {
    pressed = true;
    result = rand() % 8 + 2;
    Serial.print(result);
    Serial.print('\n');
    turnOffAll();
    digitalWrite(result,100);
    if (result == 2) {
      for (int i=0;i<50;i++) {
        digitalWrite(buzzerPin,HIGH);
        delay(5);
        digitalWrite(buzzerPin,LOW);
      }
    }
  } else if (buttonState == LOW) {
    pressed = false;
  }
}
