//Motor Driver
  //controls the speed of the motors
   const int Left_Speed = 3;
   const int Right_Speed = 2;
   //Front wheels
   const int Motor_Left1 = 23;
   const int Motor_Left2 = 22;
   //Back right wheel
   const int Motor_Right1 = 24;
   const int Motor_Right2 = 25;
 
//Ultrasonic
   const int trigPin = 9;
   const int echoPin = 10;
     
   long duration;
   int distance;
//Bluethooth
char M;
 
 
 
 void setup()
 {
 

    Serial.begin(9600); // Starts the serial communication
   
 
 //Motor_Driver
    //Motor_Left1 & Motor_Left2 controls the left wheels(in1 & in2)
    //Motor_Left1 ON & Motor_Left2 OFF means FORWARD
    //Motor_Left1 OFF & Motor_Left2 ON means BACKWARD
    //Both pins OFF/ON means STOP
    pinMode(Motor_Left1, OUTPUT);
    pinMode(Motor_Left2, OUTPUT);
    //Motor_Right1 & Motor_Right2 controls the right wheels(in3 & in4)
    //Motor_Right1 ON & Motor_Right2 OFF means FORWARD
    //Motor_Right1 OFF & Motor_Right2 ON means BACKWARD
    //Both pins OFF/ON means STOP
    pinMode(Motor_Right1, OUTPUT);
    pinMode(Motor_Right2, OUTPUT);
 
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

   // Calculating the distance in cm
   distance= duration*0.034/2;
 
// End of Ultrasonic


  
   //BLUETOOTH
    if (Serial.available()>0)
    {     
       M = Serial.read();
       switch(M)
       {
       case 'F':
        forward(255,255);
        break;
       case 'B':
        backward();
        break;
       case 'L':
        moveLeft(200);
        break;
       case 'R':
        moveRight(200);
        break;
       case 'S':
        Stop();
       }
    }

//Ultrasonic reaction
    if (distance <= 30 && distance > 15)
    {
      forward(150,150);
    }
    else if(distance <= 15)
    {
      Stop();
    }

 
 }
 
 void forward(int leftValue, int rightValue)
 {
   //Making all the motors go forward
   digitalWrite(Motor_Left1, HIGH);
   digitalWrite(Motor_Left2, LOW);
   digitalWrite(Motor_Right1, HIGH);
   digitalWrite(Motor_Right2, LOW);
 
   //Controlling the speed of the motors
   analogWrite(Left_Speed, leftValue);
   analogWrite(Right_Speed, rightValue);
 }
 void backward()
 {
   //Making all motors go Backward
   digitalWrite(Motor_Left1,HIGH);
   digitalWrite(Motor_Left2,LOW);
   digitalWrite(Motor_Right1,HIGH);
   digitalWrite(Motor_Right2,LOW) ;
   //controlling the speed of the motors
   analogWrite(Left_Speed,180);
   analogWrite(Right_Speed,180);
 }
 void moveRight(int value)
 {
   forward(255, value);
 }
 
 void moveLeft(int value)
 {
   forward(value, 255);
 }
 void Stop() 
{ 
   digitalWrite(Motor_Left1,LOW);
   digitalWrite(Motor_Left2,LOW);
   digitalWrite(Motor_Right1,LOW);
   digitalWrite(Motor_Right2,LOW);
  }
