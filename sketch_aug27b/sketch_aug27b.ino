
#include <Servo.h>          //header file
#include <math.h>


Servo axis0_servo;          //declaration of servo variable
Servo axis1_servo;
int pot = A0;
int pot_val;
int angle;
int pos = 0;     // variable to store the servo position
double theta1, theta2, alpha;
double hp;
double i = 0;

void coordinate(double x, double y);
void angles(int theta1,int theta2);


void setup() {
  Serial.begin(9600);
  pinMode(pot,INPUT);
  axis0_servo.attach(6);    //declartion of the pin no. for servo pin
  axis1_servo.attach(5);
  

}

void loop() {
  
pot_val=analogRead(pot);
angle = map(pot_val, 0, 1023,0, 180);
Serial.println(pot_val);
if(pot_val<500){
    angles(60,120);
  }
  else
  {
    coordinate(6,7);
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
void angles(int t1,int t2)
{
  axis0_servo.write(t1);    
  axis1_servo.write(t2);  
     
}
