// 서보모터사용핀을 사용합니다 
// 서보1 : IR_R_PIN / 서보2: IR_L_PIN

// 장비 1의 경우 서보1 : 2  / 서보2:4
#define IR_R_PIN 2
#define IR_L_PIN 4

// 장비 2의 경우 서보1 : 10 / 서보2:3
//#define IR_R_PIN 2
//#define IR_L_PIN 4

 
void setup()
{
  pinMode(IR_R_PIN, INPUT);         // 핀번호 선언
  pinMode(IR_L_PIN, INPUT);         // 핀번호 선언
  Serial.begin(9600);
  delay(100);
}
 
void print_ir_value(int L_val, int R_val)
{
  Serial.print("Val(L): ");
  Serial.print(L_val);
  Serial.print("\tVal(R): ");
  Serial.println(R_val);
}
void loop()
{
  // 0:WHITE or YELLOW 
  // 1:BLACK
  int val_R = digitalRead(IR_R_PIN); 
  int val_L = digitalRead(IR_L_PIN);
  print_ir_value(val_L, val_R);
  delay(50);
}
