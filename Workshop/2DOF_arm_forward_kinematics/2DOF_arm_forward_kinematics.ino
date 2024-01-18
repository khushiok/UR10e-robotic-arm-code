
#include <Servo.h>          //header file
#include <math.h>
int xc=10;                  //x coordinate of centre of circle
int yc=5;                  //y coordinate of circle of centre
int r=2;                    //radius of circle
double x1,y1;
double l1=10,l2=10;            //link length of arm
double theta1,theta2;
double a;
double x,y;


double t=0;
Servo axis0_servo;          //declaration of servo variable
Servo axis1_servo;

int pos = 0;                // variable to store the servo position

void setup()
{
  Serial.begin(9600);
  axis0_servo.attach(5);    //declartion of the pin no. for servo pin
  axis1_servo.attach(6);
}

void loop()
{
  
    for(int i=0;i<=1000;i++)
    {
      x=xc+(r*cos((PI*t)/180));
      y=yc+(r*sin((PI*t)/180));

      a=(((pow(x,2)+pow(y,2))-(pow(11,2)+pow(l2,2)))/(2*l1*l2));
      theta2=atan2(sqrt(1-pow(a,2)),a);
      theta1=atan2(y,x)-atan2(l2*sin(theta2),(l2*cos(theta2)+l1));

      theta2=theta2*180/PI;
      theta1=90+theta1*180/PI;      
      Serial.print(x);
      Serial.print("   theta2  ");
      Serial.print(y);
      Serial.print("  ");
      Serial.println(i);
      axis0_servo.write(theta1);
      axis1_servo.write(theta2);

      t=t+0.5;
    }
}
