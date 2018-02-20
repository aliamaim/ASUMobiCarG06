

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
  //Flashes the pins from 4 to 7 in order
  for(int i = 4; i < 8; i++)
  {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  //Flashes the pins from 7 to 4 in order
  for(int j = 7; j > 3; j--)
  {
    digitalWrite(j, HIGH);
    delay(100);
    digitalWrite(j, LOW);
  }
   
}
