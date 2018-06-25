//Motor Driver
  //controls the speed of the motors
   int Speed_Right = 6;
   int Speed_Left = 5;
   //Front wheels
   int Motor_RightForward = 3;
   int Motor_RightBackward = 2;
   //Back right wheel
   int Motor_LeftForward = 12;
   int Motor_LeftBackward = 11;
 
//Ultrasonic
   const int trigPin = 9;
   int echoPin = 10;
     
   long duration;
   int distance;
//Bluethooth
   char M;
   char X;

//Line Tracker
   int pinR= 4;
   int pinC= 7;
   int pinL= 8;

   int RState = 2;
   int CState = 2;
   int LState = 2;
   int State = 2;
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
  X = Serial.read();
  while(X != 'w')
  {
   RState = digitalRead(pinR);
   CState = digitalRead(pinC);
   LState = digitalRead(pinL);
   if(LState == 0 && CState == 1 && RState == 0) //GoForward
   {
    Forward(80,80);
    LastState = 1;
   }
   else if(LState == 1 && CState == 0 && RState == 0) //GoLeft
   {
    MoveLeft(15,90);
    LastState = 2;
   }
   else if(LState == 0 && CState == 0 && RState == 1) //GoRight
   {
    MoveRight(15,90);
    LastState = 3;
   }
   else if(LState == 1 && CState == 1 && RState == 1) //Intersection
   {
    Forward(80,80);
    LastState = 4;
   }
   else
   {
    switch(LastState)
    {
      case 1:

      Forward(60,60);
      break;
      case 2:
      MoveLeft(0,80);
      break;
      case 3:
      MoveRight(0,80);
      break;
      case 4:
      Forward(60,60);
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

    /* if(distance <= 35)
     {
      Stop();
      MoveRight(150, 0);
     }
     else
     {*/

      switch(M)
      {
       case 'F':
       Forward(80,80);
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
       case 'S':
       Stop();
       break; 
      }
     } 
  //}
 }



 // 1cm = 0.0251576 seconds
