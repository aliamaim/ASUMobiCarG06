//Motor Driver
  //controls the speed of the motors
   int Speed_Right = 3;
   int Speed_Left = 2;
   //Front wheels
   int Motor_RightForward = 23;
   int Motor_RightBackward = 22;
   //Back right wheel
   int Motor_LeftForward = 25;
   int Motor_LeftBackward = 24;
 
//Ultrasonic
   const int trigPin = 9;
   int echoPin = 10;
     
   long duration;
   int distance;
//Bluethooth
   char M;

//Line Tracker
   int pinR= 50;
   int pinC= 51;
   int pinL= 52;

   int RState = 0;
   int CState = 0;
   int LState = 0;
   int State = 0;
   int LastState = 0;




 
  void Forward(int leftValue, int rightValue)
 {
   //Making all the motors go forward
   digitalWrite(Motor_LeftForward, HIGH);
   digitalWrite(Motor_RightForward, HIGH);
   
   digitalWrite(Motor_LeftBackward, LOW);
   digitalWrite(Motor_RightBackward, LOW);
 
   //Controlling the speed of the motors
   analogWrite(Speed_Left, leftValue);
   analogWrite(Speed_Right, rightValue);
 }
 void Backward()
 {
   //Making all motors go Backward
   digitalWrite(Motor_LeftForward, LOW);
   digitalWrite(Motor_RightForward, LOW);
   
   digitalWrite(Motor_LeftBackward, HIGH);
   digitalWrite(Motor_RightBackward, HIGH);


   //controlling the speed of the motors
   analogWrite(Speed_Left,150);
   analogWrite(Speed_Right,150);
 }
 void MoveRight(int valueToChange, int value)
 {
   Forward(value, valueToChange);
 }
 
 void MoveLeft(int valueToChange, int value)
 {
   Forward(valueToChange, value);
 }
 void Stop() 
{ 
   digitalWrite(Motor_LeftForward, LOW);
   digitalWrite(Motor_RightForward, LOW);
   digitalWrite(Motor_LeftBackward, LOW);
   digitalWrite(Motor_RightBackward, LOW);
}
void MoveRightSharp(int value, int valueToChange)
{
   digitalWrite(Motor_LeftForward, HIGH);
   digitalWrite(Motor_RightForward, LOW);
   
   digitalWrite(Motor_LeftBackward, LOW);
   digitalWrite(Motor_RightBackward, HIGH);
 
   //Controlling the speed of the motors
   analogWrite(Speed_Left, value);
   analogWrite(Speed_Right, valueToChange);
}
void MoveLeftSharp(int valueToChange, int value)
{
   digitalWrite(Motor_LeftForward, LOW);
   digitalWrite(Motor_RightForward, HIGH);
   
   digitalWrite(Motor_LeftBackward, HIGH);
   digitalWrite(Motor_RightBackward, LOW);
 
   //Controlling the speed of the motors
   analogWrite(Speed_Left, valueToChange);
   analogWrite(Speed_Right, value);
}

 void LineTracker()
 {
  while(Serial.read() != 'w')
  {
   RState = digitalRead(pinR);
   CState = digitalRead(pinC);
   LState = digitalRead(pinL);
   if(LState == 0 && CState == 1 && RState == 0) //GoForward
   {
    Forward(100,100);
    LastState = 1;
   }
   else if(LState == 1 && CState == 0 && RState == 0) //GoLeft
   {
    MoveLeft(0,90);
    LastState = 2;
   }
   else if(LState == 0 && CState == 0 && RState == 1) //GoRight
   {
    MoveRight(90,0);
    LastState = 3;
   }
   else if(LState == 1 && CState == 1 && RState == 1) //Intersection
   {
    Forward(100,100);
    LastState = 4;
   }
   else
   {
    switch(LastState)
    {
      case '1':
      Forward(100,100);
      break;
      case '2':
      MoveLeftSharp(50,50);
      break;
      case '3':
      MoveRightSharp(50,50);
      break;
      case '4':
      Forward(100,100);
      break;
    }
   }
  }
 }

 
 void setup()
 {
 

    Serial.begin(9600); // Starts the serial communication
   
 
 //Motor_Driver
    //Both pins OFF/ON means STOP
    pinMode(Motor_LeftForward, OUTPUT);
    pinMode(Motor_LeftBackward, OUTPUT);
    //Both pins OFF/ON means STOP
    pinMode(Motor_RightForward, OUTPUT);
    pinMode(Motor_RightBackward, OUTPUT);
 
    pinMode(Speed_Left, OUTPUT);
    pinMode(Speed_Right, OUTPUT);


//Ultrasonic
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
   
//LineTracker
   pinMode(pinL, INPUT);
   pinMode(pinC, INPUT);
   pinMode(pinR, INPUT);
 }


 void loop() 
 {

 

 //Ultrasonic
   // Clears the trigPin
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);

   // Sets the trigPin on HIGH state for 10 micro seconds
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);

   // Reads the echoPin, returns the sound wave travel time in microseconds
   duration = pulseIn(echoPin, HIGH);

   // Calculating the distance in cm
   distance= duration*0.034/2;


   
   
   //BLUETOOTH
  if (Serial.available()>0)
  {
        
     M = Serial.read();
     
     if(distance <= 35)
     {
      Stop();
      MoveSharpRight(50, 50);
      delay(500);
     }
     else
     {

      switch(M)
      {
       case 'F':
       Forward(200,200);
       break;
       case 'B':
       Backward();
       break;
       case 'L':
       MoveLeft(40, 255);
       break;
       case 'R':
       MoveRight(40, 255);
       break;
       case 'W':
       LineTracker();
       break;
       case '
      }
     }
   delay(10); 
   
  }
