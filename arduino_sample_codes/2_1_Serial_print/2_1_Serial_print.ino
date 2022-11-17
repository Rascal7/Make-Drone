void setup() {
Serial.begin(9600); //통신속도 지정
Serial.print("Hello World!"); //아두이노가 보내는 것

/* java와 동일함.*/
Serial.print(); //줄 바뀜이 없음
Serial.println(); //줄 바뀜이 있음.
delay(300);
}

void loop() {

}
