# define TRIG_F 5 //Front
# define ECHO_F 6 //Front
 
void setup (){
  pinMode(TRIG_F, OUTPUT);
  pinMode(ECHO_F, INPUT);
  Serial.begin(9600);
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
  float distance_f;
  distance_f = get_distance(TRIG_F, ECHO_F, 0);
  delay(100);
  Serial.println();
}
