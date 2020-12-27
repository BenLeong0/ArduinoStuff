int n=0;
int d = 25;
const int analogPin = 0;//the analog input pin attach to
int inputValue = 0;//variable to store the value coming from sensor
int outputValue = 0;//variable to store the output value

void setup() {
  Serial.begin(9600);
}

void loop() {
  inputValue = analogRead(analogPin);//read the value from the potentiometer
  Serial.print("Input: "); //print "Input"
  Serial.println(inputValue); //print inputValue
  d = map(inputValue, 0, 1023, 5, 100);
  Serial.print("Delay: "); //print "Output"
  Serial.println(d); //print outputValue
  
  analogWrite((n+3)%15+2,255);
  analogWrite((n+2)%15+2,127);
  analogWrite((n+1)%15+2,63);
  analogWrite((n+0)%15+2,31);
  analogWrite((n-1)%15+2,15);
  analogWrite((n-2)%15+2,7);
  analogWrite((n-3)%15+2,3);
  analogWrite((n-4)%15+2,1);
  analogWrite((n-5)%15+2,1);
  analogWrite((n-6)%15+2,0);
  n++;
  delay(d);
}
