#include <IRremote.h>
#define UNKNOWN_F 5316027
#define UNKNOWN_B 2747854299
#define UNKNOWN_L 1386468383
#define UNKNOWN_R 553536955
#define UNKNOWN_S 3622325019

//Ir remote codes, funny thing i stayed till 12 coding this just for my satisfaction

#define F 16736925
#define B 16754775
#define L 16720605
#define R 16761405
#define S 16712445

int RECV_PIN = 12;
int in1=6;
int in2=7;
int in3=8;
int in4=9;
int ENA=5;
int ENB=11;
int ABS=115;

//Define which pins go where 
//Omg this code sucks -Harsh 2022

IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long val;

//Define which motors to turn on each click made on the remote

void _mForward()
{ 
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);//digital output
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward!");
}
void _mBack()
{
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go back!");
}
void _mleft()
{
  analogWrite(ENA,ABS);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
  Serial.println("go left!");
}
void _mright()
{
  analogWrite(ENA,ABS);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go right!");
}
void _mStop()
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("STOP!");  
}

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  _mStop();
  irrecv.enableIRIn();  
  Serial.begin(9600);
}

//Run code

void loop() {
  if (irrecv.decode(&results)){ 
    val = results.value;
    Serial.println(val);
    irrecv.resume();
    switch(val){
      case F: 
      case UNKNOWN_F: _mForward();break;
      case B: 
      case UNKNOWN_B: _mBack(); break;
      case L: 
      case UNKNOWN_L: _mleft(); break;
      case R: 
      case UNKNOWN_R: _mright();break;
      case S: 
      case UNKNOWN_S: _mStop(); break;
      default:break;
    }
  }
} 

//Thank you for reading my crappy code
