void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(4, HIGH);   // Sends a pulse to pin 4
  delay(500);                       // wait for 0.5 seconds
  digitalWrite(4, LOW);    // Ends the pulse
  delay(1500);                       // wait for 1.5 seconds
}
