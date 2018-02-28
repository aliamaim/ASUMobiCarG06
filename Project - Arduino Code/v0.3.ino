//F stands for Front,B for back, L for left, R for right
//for example Motor_FL1 stands for Front left motor input1 in motor driver
  //Front left wheel
  const int Motor_FL1 = 22;
  const int Motor_FL2 = 23;
  //Back left wheel
  const int Motor_BL1 = 24;
  const int Motor_BL2 = 25;
  //Front right wheel
  const int Motor_FR1 = 26;
  const int Motor_FR2 = 27;
  //Back right wheel
  const int Motor_BR1 = 28;
  const int Motor_BR2 = 29;
   


void setup()
{

//Motor_Driver_1
//Input pins going to the motor driver of the two LEFT wheels motors
   //Motor_FL1 & Motor_FL2 controls the front wheel (in1 & in2)
   //Motor_FL1 OFF & Motor_FL2 ON means FORWARD
   //Motor_FL1 ON & Motor_FL2 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(Motor_FL1, OUTPUT);
   pinMode(Motor_FL2, OUTPUT);
   //Motor_BL1 & Motor_BL2 controls the rear wheel (in3 & in4)
   //Motor_BL1 OFF & Motor_BL2 ON means FORWARD
   //Motor_BL1 ON & Motor_BL2 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(Motor_BL1, OUTPUT);
   pinMode(Motor_BL2, OUTPUT);

//Motor_Driver_2
//Input pins going to the motor driver of the two RIGHT wheels motors
   //Motor_FR1 & Motor_FR2 controls the front wheel (in1 & in2)
   //Motor_FR1 OFF & Motor_FR2 ON means FORWARD
   //Motor_FR1 ON & Motor_FR2 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(Motor_FR1, OUTPUT);
   pinMode(Motor_FR2, OUTPUT);
   //Motor_BR1 & Motor_BR2 controls the rear wheel (in3 & in4)
   //Motor_BR1 OFF & Motor_BR2 ON means FORWARD
   //Motor_BR1 ON & Motor_BR2 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(Motor_BR1, OUTPUT);
   pinMode(Motor_BR2, OUTPUT);

  
}

void loop() 
{



  

}
