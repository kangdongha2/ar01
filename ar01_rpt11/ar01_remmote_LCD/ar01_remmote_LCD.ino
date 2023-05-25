/*
 예제 8.2
 적외선 리모컨을 이용한 LED 제어  
*/

// 적외선 리모컨 라이브러리를 불러온다.  
#include <IRremote.h>

// 적외선 수신부가 연결될 핀을 설정한다.
int irPin = 11;

// LED에 연결된 핀을 설정한다.
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

// LED 제어용 코드 (리모컨에 맞게 수정한다)
long on1  = 0xFF30CF;
long off1 = 0xFF38C7;
long on2  = 0xFF18E7;
long off2 = 0xFF5AA5;
long on3  = 0xFF7A85;
long off3 = 0xFF42BD;
long on4  = 0xFF10EF;
long off4 = 0xFF4AB5;

// 적외선 수신부가 연결된 핀을 리모컨 수신 핀으로 설정한다.
IRrecv irrecv(irPin);

// 수신된 신호의 결과를 results 변수로 설정한다.
decode_results results;

void setup()
{
  lcd.init();  // LCD초기 설정             
  lcd.backlight(); // LCD초기 설정  
  lcd.setCursor(0,0); //텍스트가 LCD에 나타날 위치
  lcd.print("LED1 is on"); 
  lcd.setCursor(3,1);
  lcd.print("How are you?"); 
}

void setup()
{
  // 시리얼 통신을 설정한다.
  Serial.begin(9600);

  // 적외선 리모컨 수신을 시작한다.
  irrecv.enableIRIn();

  // 13번 핀에 연결된 LED를 리모컨 수신시 점멸시킨다.
  irrecv.blink13(true);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop()
{
  // 수신된 코드가 있을 때 실행한다.
  if (irrecv.decode(&results)){
    // 0xFFFFFFFF 값을 제외하고 출력한다.
    if(results.value != 0xFFFFFFFF){
      // 수신된 코드가 on1과 같을 때
      if(results.value == on1){
      	digitalWrite(led1, HIGH);
        Serial.println("LED1 is ON");
      }
      // 수신된 코드가 off1과 같을 때
      if(results.value == off1){
      	digitalWrite(led1, LOW);
        Serial.println("LED1 is OFF");
      }
      // 수신된 코드가 on2와 같을 때
      if(results.value == on2 ){
      	digitalWrite(led2, HIGH);
        Serial.println("LED2 is ON");
      }
      // 수신된 코드가 off2와 같을 때
      if(results.value == off2 ){
      	digitalWrite(led2, LOW);
        Serial.println("LED2 is OFF");
      }
      // 수신된 코드가 on3와 같을 때
      if(results.value == on3){
      	digitalWrite(led3, HIGH);
        Serial.println("LED3 is ON");
      }
      // 수신된 코드가 off3와 같을 때
      if(results.value == off3){
      	digitalWrite(led3, LOW);
        Serial.println("LED3 is OFF");
      }
    // 수신된 코드가 on4와 같을 때
      if(results.value == on4){
      	digitalWrite(led4, HIGH);
        Serial.println("LED4 is ON");
      }
    // 수신된 코드가 off4와 같을 때
      if(results.value == off4){
      	digitalWrite(led4, LOW);
        Serial.println("LED4 is OFF");
      }
    };
    // 다음 수신을 위해서 준비한다.
    irrecv.resume();
  }
}
