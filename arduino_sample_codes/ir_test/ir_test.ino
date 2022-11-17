#define IR_R_PIN 2

void setup() {
  pinMode(IR_R_PIN, INPUT); // 핀번호 선언
  Serial.begin(9600);
}

void print_ir_value(int R_val){
  Serial.print("\tVal(R): ");
  Serial.println(R_val);
}
void loop() {
  int val_R = digitalRead(IR_R_PIN);
  print_ir_value(val_R);
  delay(50);
}
