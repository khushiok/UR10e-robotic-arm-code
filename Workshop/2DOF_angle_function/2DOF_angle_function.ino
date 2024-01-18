
#include <Servo.h>          //header file
#include <math.h>
Servo axis0_servo;          //declaration of servo variable
Servo axis1_servo;

int pos = 0;                // variable to store the servo position

void angles(int theta1,int theta2);
void setup()
{
  axis0_servo.attach(6);    //declartion of the pin no. for servo pin
  axis1_servo.attach(5);
}
void loop()
{
  while(1)
  {
    angles(0,0);
  }   
}

void angles(int theta1,int theta2)
{
  axis0_servo.write(theta1);    
  axis1_servo.write(theta2);     
}
