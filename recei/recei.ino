
#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>
#define Channel 11

RF24 radio(10, 9); // CE, CSN
float X_out, Y_out, Z_out;
const byte address[6] = "00001";
int ENA = 5;
int ENB = 3;
#define FR1 A1
#define FR2 A2
#define FL1 A3 
#define FL2 A5

void setup() {
  
  Serial.begin(9600);
  pinMode(ENB, OUTPUT);
  pinMode(ENA, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setChannel(Channel);
  radio.startListening();

   X_out=10;
   Y_out=1;
   Z_out=-255;
   analogWrite(ENA, 140);
   analogWrite(ENB, 140);

}

void loop() {
  if (radio.available()) {
    //char text[32] = "";
    radio.read(&X_out, sizeof(X_out));
    radio.read(&Y_out, sizeof(Y_out));
    radio.read(&Z_out, sizeof(Z_out));
    Serial.print("Xa= ");
  Serial.print(X_out);
  Serial.print("   Ya= ");
  Serial.print(Y_out);
  Serial.print("   Za= ");
  Serial.println(Z_out);
  }
  if(Y_out<-30&&Z_out>-250)          //forword
  {
  digitalWrite(FR1,LOW);  
  digitalWrite(FR2,HIGH);  
  digitalWrite(FL1,LOW);  
  digitalWrite(FL2,HIGH);  
  }
  else if(Y_out>30&&Z_out<-250)       //reverse
  {
  digitalWrite(FR1,HIGH);  
  digitalWrite(FR2,LOW);  
  digitalWrite(FL1,HIGH);  
  digitalWrite(FL2,LOW);  
  }
 else if(X_out>30&&Y_out<5)          //right
  {
    digitalWrite(FR1,LOW);  
  digitalWrite(FR2,LOW);  
  digitalWrite(FL1,LOW);  
  digitalWrite(FL2,HIGH); 
  
  }
  else if(X_out<-30&&Y_out<0)      //left
  {
   
  digitalWrite(FR1,LOW);  
  digitalWrite(FR2,HIGH);  
  digitalWrite(FL1,LOW);  
  digitalWrite(FL2,LOW);
}
else if(X_out>0&&Y_out<0&&Z_out<-280)
  {
   
  digitalWrite(FR1,LOW);  
  digitalWrite(FR2,LOW);  
  digitalWrite(FL1,LOW);  
  digitalWrite(FL2,LOW);
  delay(500);
}
else if(X_out==0&&Y_out==0&&Z_out==0)
{
  digitalWrite(FR1,LOW);  
  digitalWrite(FR2,LOW);  
  digitalWrite(FL1,LOW);  
  digitalWrite(FL2,LOW);
  delay(500);
}
}

