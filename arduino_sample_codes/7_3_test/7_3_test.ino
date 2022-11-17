#include <Servo.h>

//IR센서
#define IR_R_PIN 2
#define IR_L_PIN 4

//좌우 제어
#define DIR_R 12  //방향
#define DIR_L 10
#define PWM_R 11   //속도
#define PWM_L 3

//앞뒤 거리
# define TRIG_F 5 //Front
# define ECHO_F 6 //Front
# define TRIG_B 8 //Back
# define ECHO_B 7 //Back

//서보 핀 번호
#define SERVO_F 2
#define SERVO_B 4

//전역 변수
float distance_f, distance_b;
int Speed = 150;



void setup() {
  //좌우 제어
  pinMode(DIR_R,OUTPUT);
  pinMode(DIR_L,OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(PWM_L, INPUT);
  
  //앞뒤 거리
  pinMode(TRIG_F, OUTPUT);
  pinMode(ECHO_F, INPUT);
  pinMode(TRIG_B, OUTPUT);
  pinMode(ECHO_B, INPUT);


  // 핀번호 선언
  pinMode(IR_R_PIN, INPUT); 
  pinMode(IR_L_PIN, INPUT); 

  Serial.begin(9600);
}

void loop() {
  
  Serial.println();
  Forward(55);
  
}

float get_distance(int TRIG, int ECHO, bool mode)
{
  float duration, distance;
  digitalWrite(TRIG, HIGH);
  //delay(10);
  digitalWrite (TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = ((float)(340*duration)/10000) / 2;
  if (mode == 0)
    Serial.print("F : ");
  else 
    Serial.print("B : ");
  Serial.print(distance);
  Serial.print("cm  ");
  return distance;  
}

void Forward(int val)
{
  int val_R = digitalRead(IR_R_PIN);
  int val_L = digitalRead(IR_L_PIN);
  
  digitalWrite(DIR_R,HIGH);
  digitalWrite(DIR_L,HIGH);
  analogWrite(PWM_R,val);
  analogWrite(PWM_L,val);
  distance_f = get_distance(TRIG_F, ECHO_F, 0);
  distance_b = get_distance(TRIG_B, ECHO_B, 1);
  
  if (distance_f<=30){
    Stop();
    delay(1000);

  }
  
  if(val_R==0 || val_L==0){
    line_danger(val_R, val_L, Speed+30);
  }
}

void Stop()
{
  analogWrite(PWM_R,0);
  analogWrite(PWM_L,0);
} 

void line_danger(int R_val, int L_val, int val)
{
  Serial.print("\tVal(R): ");
  Serial.print(R_val);
  Serial.print("\tVal(L): ");
  Serial.print(L_val);

  if(R_val==0)
  {
    digitalWrite(DIR_R, HIGH);
    digitalWrite(DIR_L, LOW);
    analogWrite(PWM_R, val);
    analogWrite(PWM_L, val);
    delay(100);
  }
  if(L_val==0)
  {
    digitalWrite(DIR_R, LOW);
    digitalWrite(DIR_L, HIGH);
    analogWrite(PWM_R, val);
    analogWrite(PWM_L, val);
    delay(100);
  }
}
