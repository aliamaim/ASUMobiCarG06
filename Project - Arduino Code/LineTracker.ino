

//Motor Driver
  //controls the speed of the motors
   const int Speed_Right = 3;
   const int Speed_Left = 2;
   //Front wheels
   const int Motor_RightForward = 23;
   const int Motor_RightBackward = 22;
   //Back right wheel
   const int Motor_LeftForward = 25;
   const int Motor_LeftBackward = 24;
   
//Bluethooth
   char M;

//Line Tracker
int pinR= 28;
int pinC= 26;
int pinL= 27;

int RState = 1;
int CState = 1;
int LState = 1;




 
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


//LineTracker
   pinMode(pinL, INPUT);
   pinMode(pinC, INPUT);
   pinMode(pinR, INPUT);
 }


 void loop() 
 {


   RState = digitalRead(pinR);
   CState = digitalRead(pinC);
   LState = digitalRead(pinL);
   if ((LState == 0) && (CState == 1) && (RState == 0)) //1ST CASE MID
   {
     Forward(100,100);
   }
   else if((LState == 0) && (CState == 1) && (RState == 1) ) //2ND Slight right
   {
     MoveRight(90,0);
   }
   else if((LState == 0) && (CState == 0) && (RState == 1)) //3RD sharp right
   {
    MoveRightSharp(50,50);
   }
   else if((LState == 1) && (CState == 1) && (RState == 0)) //4TH slight left
   {
     MoveLeft(0,90);
   }
   else if((LState == 1) && (CState == 0) && (RState == 0)) //5TH sharp left
   {
     MoveLeftSharp(50,50);  
   }
   else if((LState == 1) && (CState == 1) && (RState == 1)) //6TH Intersection case
   {
     Forward(80,80);
   }
   else if((LState == 0) && (CState == 0) && (RState == 0)) //7th No line detected
   {
    Stop();
   }
}
