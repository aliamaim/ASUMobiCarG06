

  //controls the speed of the motors
  const int Left_Speed = 3;
  const int Right_Speed = 2;
  //Front wheels
  const int Motor_Front1 = 23;
  const int Motor_Front2 = 22;
  //Back right wheel
  const int Motor_Back1 = 24;
  const int Motor_Back2 = 25;



void setup()
{

//Motor_Driver
   //Motor_Front1 & Motor_Front2 controls the front wheels(in1 & in2)
   //Motor_Front1 OFF & Motor_Front2 ON means FORWARD
   //Motor_Front1 ON & Motor_Front2 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(Motor_Front1, OUTPUT);
   pinMode(Motor_Front2, OUTPUT);
   //Motor_Back1 & Motor_Back2 controls the back wheels(in3 & in4)
   //Motor_Back1 OFF & Motor_Back2 ON means FORWARD
   //Motor_Back1 ON & Motor_Back2 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(Motor_Back1, OUTPUT);
   pinMode(Motor_Back2, OUTPUT);

   pinMode(Left_Speed, OUTPUT);
   pinMode(Right_Speed, OUTPUT);


  
}

void loop() 
{

}

void forward(int leftValue, int rightValue)
{
  //Making all the motors go forward
  digitalWrite(Motor_Front1, LOW);
  digitalWrite(Motor_Front2, HIGH);
  digitalWrite(Motor_Back1, LOW);
  digitalWrite(Motor_Back2, HIGH);

  //Controlling the speed of the motors
  analogWrite(Left_Speed, leftValue);
  analogWrite(Right_Speed, rightValue);
}
void backward()
{
  //Making all motors go Backward
  digitalWrite(Motor_Front1,HIGH);
  digitalWrite(Motor_Front2,LOW);
  digitalWrite(Motor_Back1,HIGH);
  digitalWrite(Motor_Back2,LOW) ;
  //controlling the speed of the motors
  analogWrite(Left_Speed,155);
  analogWrite(Right_Speed,155);
}
void moveRight(int value)
{
  forward(255, value);
}

void moveLeft(int value)
{
  forward(value, 255);
}

//Motor Driver
  //controls the speed of the motors
   const int Left_Speed = 3;
   const int Right_Speed = 2;
   //Front wheels
   const int Motor_Front1 = 23;
   const int Motor_Front2 = 22;
   //Back right wheel
   const int Motor_Back1 = 24;
   const int Motor_Back2 = 25;
 
//Ultrasonic
   const int trigPin = 9;
   const int echoPin = 10;
     
   long duration;
   int distance;

 
 
 
 void setup()
 {

    Serial.begin(9600); // Starts the serial communication
 
 //Motor_Driver
    //Motor_Front1 & Motor_Front2 controls the front wheels(in1 & in2)
    //Motor_Front1 OFF & Motor_Front2 ON means FORWARD
    //Motor_Front1 ON & Motor_Front2 OFF means BACKWARD
    //Both pins OFF/ON means STOP
    pinMode(Motor_Front1, OUTPUT);
    pinMode(Motor_Front2, OUTPUT);
    //Motor_Back1 & Motor_Back2 controls the back wheels(in3 & in4)
    //Motor_Back1 OFF & Motor_Back2 ON means FORWARD
    //Motor_Back1 ON & Motor_Back2 OFF means BACKWARD
    //Both pins OFF/ON means STOP
    pinMode(Motor_Back1, OUTPUT);
    pinMode(Motor_Back2, OUTPUT);
 
    pinMode(Left_Speed, OUTPUT);
    pinMode(Right_Speed, OUTPUT);


//Ultrasonic
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input

 
 
   
 }
 
 void loop() 
 {


// *** Ultrasonic ***  
   // Clears the trigPin
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);

   // Sets the trigPin on HIGH state for 10 micro seconds
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);

   // Reads the echoPin, returns the sound wave travel time in microseconds
   duration = pulseIn(echoPin, HIGH);

   // Calculating the distance
   distance= duration*0.034/2;

   // Prints the distance on the Serial Monitor
   Serial.print("Distance: ");
   Serial.println(distance);
// End of Ultrasonic
 
 }
 
 void forward(int leftValue, int rightValue)
 {
   //Making all the motors go forward
   digitalWrite(Motor_Front1, LOW);
   digitalWrite(Motor_Front2, HIGH);
   digitalWrite(Motor_Back1, LOW);
   digitalWrite(Motor_Back2, HIGH);
 
   //Controlling the speed of the motors
   analogWrite(Left_Speed, leftValue);
   analogWrite(Right_Speed, rightValue);
 }
 void backward()
 {
   //Making all motors go Backward
   digitalWrite(Motor_Front1,HIGH);
   digitalWrite(Motor_Front2,LOW);
   digitalWrite(Motor_Back1,HIGH);
   digitalWrite(Motor_Back2,LOW) ;
   //controlling the speed of the motors
   analogWrite(Left_Speed,155);
   analogWrite(Right_Speed,155);
 }
 void moveRight(int value)
 {
   forward(255, value);
 }
 
 void moveLeft(int value)
 {
   forward(value, 255);
 }
 




