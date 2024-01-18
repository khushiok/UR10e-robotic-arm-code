
#include <Servo.h>          //header file
#include <math.h>

double x = 20, y = 0;

Servo axis0_servo;          //declaration of servo variable
Servo axis1_servo;

int pos = 0;                // variable to store the servo position
double theta1, theta2, alpha;
double hp;
double i = 0;

void coordinate(double x, double y);

void setup()
{
  Serial.begin(9600);
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

  i = 0;
  while( i < 5 ) 
  {
    i=i+0.001;
    coordinate(5 + i, 0);
  }
  i=0;
  while(i<5)
  {
     i=i+0.001;
    coordinate(10,i);
  }
  i=0;
  while(i<5)
  {
     i=i+0.001;
    coordinate(10-i,5);
  }
   i=0;
  while(i<5)
  {
     i=i+0.001;
    coordinate(5 ,5-i);
  }
}

void coordinate(double x, double y)
{
  hp = sqrt(pow(x, 2) + pow(y, 2));
  alpha = asin(hp / 20);
  theta2 = 2 * alpha * 180 / PI;
  theta1 = atan2(y, x) * 180 / PI + ((180 - theta2) / 2);

  axis0_servo.write(theta1);
  axis1_servo.write(theta2);
}
