int d = 60;
int startPort = 2;
int endPort = 9;
int lengthOfBar = 4;
int overlap = 3;

void setup() {
  for (int i=startPort; i<=endPort; i++) {
    pinMode(i,OUTPUT);
//    if (i<=4) {
//      digitalWrite(i,HIGH);
//    }
  }
}

void f(int n) {
  for (int i=startPort;i<=endPort;i++) {
    digitalWrite(i,LOW);      // Turn off all lights
  }

  for (int i=n;i<n+lengthOfBar;i++) {
    if (startPort <= i <= endPort) {
      digitalWrite(i, HIGH);  // Turn on n -> n+len
    }
  }
}

void loop() {
  while (true) {
    for (int i=startPort-overlap;i<endPort-lengthOfBar+overlap+1;i++) {
      f(i);
      delay(d);
    }

    for (int i=endPort-lengthOfBar+overlap+1;i>startPort-overlap;i--) {
      f(i);
      delay(d);      
    }
  }
}
