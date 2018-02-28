void setup()
{

//Motor_Driver_1
//Input pins going to the motor driver of the two LEFT wheels motors
   //22 & 23 controls the front wheel (in1 & in2)
   //22 OFF & 23 ON means FORWARD
   //22 ON & 23 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(22, OUTPUT);
   pinMode(23, OUTPUT);
   //24 & 25 controls the rear wheel (in3 & in4)
   //24 OFF & 25 ON means FORWARD
   //24 ON & 25 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(24, OUTPUT);
   pinMode(25, OUTPUT);

//Motor_Driver_2
//Input pins going to the motor driver of the two RIGHT wheels motors
   //26 & 27 controls the front wheel (in1 & in2)
   //26 OFF & 27 ON means FORWARD
   //26 ON & 27 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(26, OUTPUT);
   pinMode(27, OUTPUT);
   //28 & 29 controls the rear wheel (in3 & in4)
   //28 OFF & 29 ON means FORWARD
   //28 ON & 29 OFF means BACKWARD
   //Both pins OFF/ON means STOP
   pinMode(28, OUTPUT);
   pinMode(29, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:

}


