
#include <Servo.h>          //header file

Servo axis0_servo;          //declaration of servo variable
Servo axis1_servo;

int pos = 0;                // variable to store the servo position

void setup()
{
  axis0_servo.attach(5);    //declartion of the pin no. for servo pin
  axis1_servo.attach(6);
}

void loop()
{
       /*-----------------------------------------------  Servo testing  --------------------------------------------------*/
/*
     for (pos = 0; pos <= 180; pos += 1)  // goes from 0 degrees to 180 degrees
    {
        axis0_servo.write(pos);              // tell servo to go to position in variable 'pos'
        axis1_servo.write(pos);
        delay(15);                       // waits 15 ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1)  // goes from 180 degrees to 0 degrees
    {
       axis0_servo.write(pos);              // tell servo to go to position in variable 'pos'
       axis1_servo.write(pos);
        delay(15);                       // waits 15 ms for the servo to reach the position
    }
*/  
      /*---------------------------------------  arm orinetation setting  -------------------------------------------------*/
/*
  axis0_servo.write(90);        // for setting the arm in proper orientation
  axis1_servo.write(90);
  while(1);                     //to stop the code 
  */
      /*--------------------------------------------------   MAIN CODE  --------------------------------------------------*/

  axis0_servo.write(180-5);      // to bring the servo at the starting point
  axis1_servo.write(0+10);
  delay(3000);                    // wait for sometime 

///////////////////////////////////////////////////////////////////////////////////
  for(int i=5;i<90;i++)          // for drawing the straight line.
  {
     axis0_servo.write(180-i);
     axis1_servo.write(0+i*2);                  
     delay(50);  
  }
////////////////////////////////////////////////////////////////////////////////////    
   for(int i=0;i<170;i++)          // for semi arc
  {
     axis1_servo.write(180-i);                  
     delay(20);  
  }
  while(1);
 
}
