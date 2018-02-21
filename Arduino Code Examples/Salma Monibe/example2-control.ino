  
  const int ledPin= 4;
  const int ledPin1= 5;
  const int ledPin2= 6;
  const int ledPin3= 7;
 void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay (1000);
  digitalWrite(ledPin, LOW);
  
  digitalWrite(ledPin1, HIGH);
  delay (1000);
  digitalWrite(ledPin1, LOW);
  
  digitalWrite(ledPin2, HIGH);
  delay (1000);
  digitalWrite(ledPin2, LOW);
  
  digitalWrite(ledPin3, HIGH);
  delay (1000);
  digitalWrite(ledPin3, LOW);

  digitalWrite(ledPin2, HIGH);
  delay (1000);
  digitalWrite(ledPin2, LOW);

  digitalWrite(ledPin1,HIGH);
  delay (1000);
  digitalWrite(ledPin1, LOW);

}
