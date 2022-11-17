void setup() {
Serial.begin(9600);
}

void loop() {
  /* 시리얼 값을 입력할 때까지 대기하고 있다가 입력 시 읽어드리고 출력 */
  if(Serial.available()){ //시리얼통신 가능하면
      char data = Serial.read(); //읽고
      Serial.print(data); //출력
      Serial.print(" : ");
      Serial.print(data);
      Serial.println("를 입력하였습니다.");
  }
}
