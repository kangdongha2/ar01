/*
 DIY-2
*/

// start number
int number = 0;

// 문자열 두가지를 설정한다.
String stringValue[]={"Binary:","Hexadecimal"}; // array


void setup() {
  // 9600bps로 시리얼 통신 설정
  Serial.begin(9600);
}

void loop() {
  

  // 'char Value'를 출력하고 문자열과 숫자를 변수 유형별로 출력한다.
  Serial.print("Number = ");
  Serial.print(number);
  Serial.print(", ");
  Serial.print(stringValue[0]); 
  Serial.print(number,BIN); 
  Serial.println(", ");
  Serial.print(stringValue[1]);
  Serial.print(number, HEX);

  Serial.println();   
  number++;     // number 1 증가
  
  if(number > 15) {
    Serial.print("Mission completed!");
    delay(100);
    exit(0);

    
  }
  
  delay(100);  // 1초동안 지연시킨다.
}
