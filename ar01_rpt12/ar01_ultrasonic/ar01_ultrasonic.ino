/*
 예제 6.7
 초음파 거리센서를 이용한 거리 측정  
*/

// 트리거 핀과 에코 핀 번호를 설정한다.
const char trigPin = 13;
const char echoPin = 12;
 
// 펄스 폭과 거리 변수 설정  
int pulseWidth;
int distance;
int distanceOld;
  
void setup() {
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
}

void loop(){
  // 10us의 트리거 신호를 HC-SR04로 내보낸다.
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delayMicroseconds(10);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delayMicroseconds(5);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  double duration = pulseIn(12, HIGH);
  double cm = duration * 340 / 10000 / 2;

  if (cm < 20) {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  else if (cm < 60) {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);    
  }
  else {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
  delay(100);
}
