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
  
  Serial.begin(9600);
}

void loop() {
  float distance_f, distance_b;
  distance_f = get_distance(TRIG_F, ECHO_F, 0);
  distance_b = get_distance(TRIG_B, ECHO_B, 1);
  delay(100);
  Serial.println();

  int Speed = 150;
  
  Forward(Speed);
  
  if (distance_f<=20){
    turn_half(Speed);
    delay(400);
    Stop();
    delay(500);
  }
  if (distance_b<=20){
    turn_half(Speed);
    delay(400);
    Stop();
    delay(500);
  }
}

float get_distance(int TRIG, int ECHO, bool mode)
{
  float duration, distance;
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

void turn_half(int val)
{
  // 반바퀴(뒤로돌기) 구현 왼쪽으로 돌기
  digitalWrite(DIR_R, HIGH);
  digitalWrite(DIR_L, LOW);
  analogWrite(PWM_R, val);
  analogWrite(PWM_L, val);
  delay(300);
}
void Forward(int val)
{
  digitalWrite(DIR_R,HIGH);
  digitalWrite(DIR_L,HIGH);
  analogWrite(PWM_R,val);
  analogWrite(PWM_L,val);
}

void Stop()
{
  analogWrite(PWM_R,0);
  analogWrite(PWM_L,0);
} 
