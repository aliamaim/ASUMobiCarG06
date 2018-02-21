int i=4;
int j=4;
void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

}

void loop() {
  for(i=4;i<7;i++)
  {
     digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
    
  }
  for(j=4;j>0;j--)
  {
     digitalWrite(j, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(j, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
    
    
  }
  

}
