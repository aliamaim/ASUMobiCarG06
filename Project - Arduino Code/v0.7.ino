
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
 
//Ultrasonic
   const int trigPin = 9;
   const int echoPin = 10;
     
   long duration;
   int distance;
//Bluethooth
   char M;



 
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

 float Ultrasonic()
 {
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

   return distance;
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
 }


 void loop() 
 {
   
   //BLUETOOTH

   if (Serial.available()>0)
    {
        
     M = Serial.read();
     
     if(Ultrasonic() <= 20)
     {
      Stop();
      delay(200);
      MoveRight(0, 100);
      delay(1000);
     }
     else
     {

     switch(M)
     {
      case 'F':
      Forward(230,230);
      break;
      case 'B':
      Backward();
      break;
      case 'L':
      MoveLeft(40, 220);
      break;
      case 'R':
      MoveRight(40, 220);
      break;
      case 'S':
      Stop();      
     }
    }
   }
   else
   {
    Stop();
   } 
}


