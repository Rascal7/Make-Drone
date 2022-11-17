#include <Servo.h>    //서보모터 라이브러리 include

#define SERVO_B 4
 
Servo servo_b;    //서보모터 객체 선언
 
void setup()
{
    Serial.begin(9600);
    servo_b.attach(SERVO_B);    //서보모터 초기화
}
 
void loop()
{
    int angle;    //각도 변수 선언
    
    //30 -> 150도로 서보모터 움직임
    for (angle=30; angle<=150; angle+=60)
    {
        servo_b.write(angle);    //angle(각도)값으로 서보모터 제어
        Serial.println(angle);   //각도 값 출력
        delay(500);              //delay로 각도의 변화 속도를 조절
    }
    delay(500);
    //150 -> 30도로 서보모터 움직임
    for (angle=150; angle>=30; angle-=60)
    {
        servo_b.write(angle);    //angle(각도)값으로 서보모터 제어
        Serial.println(angle);   //각도 값 출력
        delay(500);              //delay로 각도의 변화 속도를 조절
    }
    delay(500);
	servo_b.write(90);    //angle(각도)값으로 서보모터 제어
	delay(500);;
}
