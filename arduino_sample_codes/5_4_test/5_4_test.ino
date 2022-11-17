#include <Servo.h>    //서보모터 라이브러리 include

# define TRIG_F 5 //Front
# define ECHO_F 6 //Front
 
# define TRIG_B 8 //Back
# define ECHO_B 7 //Back

#define SERVO_F 2
#define SERVO_B 4
Servo servo_f;    //서보모터 객체 선언
Servo servo_b;    //서보모터 객체 선언

int led=13;

void setup (){
  pinMode(TRIG_F, OUTPUT);
  pinMode(ECHO_F, INPUT);
  pinMode(TRIG_B, OUTPUT);
  pinMode(ECHO_B, INPUT);
  Serial.begin(9600);
  pinMode(led,OUTPUT);

  Serial.begin(9600);
  servo_f.attach(SERVO_F);    //서보모터 초기화
  servo_b.attach(SERVO_B);    //서보모터 초기화
}

float get_distance(int TRIG, int ECHO, bool mode)
{
  float duration, distance;
  digitalWrite(TRIG, HIGH);
  delay(10);
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

void loop(){
  float distance_f, distance_b;
  int angle = 90;
  int angles[] = {90,150,90,30};
  int angles_size = sizeof(angles)/ sizeof(angles[0]);
  Serial.println();
  digitalWrite(led,LOW);
  
  distance_f = get_distance(TRIG_F, ECHO_F, 0);
    if (distance_f<=20){
    digitalWrite(led,HIGH);
    delay(500);
    for (int i=0; i<angles_size; i++)
    {
        angle = angles[i];
        servo_f.write(angle);    //angle(각도)값으로 서보모터 제어
        servo_b.write(angle);
 //     Serial.println(angle);        //각도 값 출력
        delay(500);                    //delay로 각도의 변화 속도를 조절
    }
  }
  servo_f.write(90);
  
  distance_b = get_distance(TRIG_B, ECHO_B, 1);
    if (distance_b<=20){
    digitalWrite(led,HIGH);
    delay(500);
    for (int i=0; i<angles_size; i++)
    {
        angle = angles[i];
        servo_f.write(angle);    //angle(각도)값으로 서보모터 제어
        servo_b.write(angle);
//      Serial.println(angle);        //각도 값 출력
        delay(500);                    //delay로 각도의 변화 속도를 조절
    }
  }
  servo_f.write(90);
  
  delay(100);






}
