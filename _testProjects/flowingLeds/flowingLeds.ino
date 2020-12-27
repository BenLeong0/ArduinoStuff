int d = 50;

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
  while (true) {
    for (int i=2;i<=8;i++) {
      digitalWrite(f(i),HIGH);
      digitalWrite(f(i+1),HIGH);
      if (i+2<=9) {
        digitalWrite(f(i+2),HIGH);
        if (i+3<=9){
          digitalWrite(f(i+3),HIGH);
        }
      }
      digitalWrite(f(i-1),LOW);
      delay(d);
    }
    delay(d);
    
    for (int i=7;i>=0;i--) {
      if (i>=2) {
        digitalWrite(f(i),HIGH);
        if (i>=1) {
          digitalWrite(f(i+1),HIGH);
        }
      }
      if (i+2<=9) {
        digitalWrite(f(i+2),HIGH);
        if (i+3<=9){
          digitalWrite(f(i+3),HIGH);
          if (i+4<=9){
            digitalWrite(f(i+4),LOW);
          }
        }
      }
      delay(d);
    }
    delay(d);
  }
}
