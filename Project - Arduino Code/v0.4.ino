

  //controls the speed of the motors
  const int Left_Speed = 2;
  const int Right_Speed = 3;
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


  
}

void loop() 
{
digitalWrite(Motor_Front1, LOW);
digitalWrite(Motor_Front2, HIGH);
digitalWrite(Motor_Back1, LOW);
digitalWrite(Motor_Back2, HIGH);
}

void forward(int value1, int value2)
{
  //Making all the motors go forward
  digitalWrite(Motor_Front1, LOW);
  digitalWrite(Motor_Front2, HIGH);
  digitalWrite(Motor_Back1, LOW);
  digitalWrite(Motor_Back2, HIGH);

  //Controlling the speed of the motors
  analogWrite(Left_Speed, value1);
  analogWrite(Right_Speed, value2);
}

void moveRight(int value)
{
  forward(255, value);
}

void moveLeft(int value)
{
  forward(value, 255);
}


