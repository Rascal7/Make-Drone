#include <Servo.h>    //서보모터 라이브러리 include

#define SERVO_F 2
#define SERVO_B 4
 
Servo servo_f;    //서보모터 객체 선언
Servo servo_b;    //서보모터 객체 선언
 
void setup()
{
    Serial.begin(9600);
    servo_f.attach(SERVO_F);    //서보모터 초기화
    servo_b.attach(SERVO_B);    //서보모터 초기화
}
 
void loop()
{
    int angle = 90;
    int angles[] = {90,150,90,30};
    int angles_size = sizeof(angles)/ sizeof(angles[0]);
    //45 -> 135도로 서보모터 움직임
    for (int i=0; i<angles_size; i++)
    {
        angle = angles[i];
        servo_f.write(angle);    //angle(각도)값으로 서보모터 제어
        servo_b.write(angle);
        Serial.println(angle);        //각도 값 출력
        delay(500);                    //delay로 각도의 변화 속도를 조절
    }
}
