
  int i = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  while(i == 0)
  {
  //Blinking the led on pin 4
  digitalWrite(4, HIGH);  
  delay(100);                       
  digitalWrite(4, LOW);  
  //Blinking the led on pin 5
  digitalWrite(5, HIGH);  
  delay(100);                       
  digitalWrite(5, LOW); 
  //Blinking the led on pin 6
  digitalWrite(6, HIGH);  
  delay(100);                       
  digitalWrite(6, LOW);
  //Blinking the led on pin 7
  digitalWrite(7, HIGH);  
  delay(100);                       
  digitalWrite(7, LOW); 
  i = 1; 
  }
  while(i == 1)
  {
  //Blinking the led on pin 4
  digitalWrite(7, HIGH);  
  delay(100);                       
  digitalWrite(7, LOW);  
  //Blinking the led on pin 5
  digitalWrite(6, HIGH);  
  delay(100);                       
  digitalWrite(6, LOW); 
  //Blinking the led on pin 6
  digitalWrite(5, HIGH);  
  delay(100);                       
  digitalWrite(5, LOW);
  //Blinking the led on pin 7
  digitalWrite(4, HIGH);  
  delay(100);                       
  digitalWrite(4, LOW);  
  i = 0;
  }
   
}
