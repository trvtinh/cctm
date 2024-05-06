int motion = 13 ;

void setup(){
  Serial.begin(115200);
  pinMode(motion , INPUT) ;
}

void loop(){
  int val = digitalRead(motion);
  if ( val == 1){
    Serial.println("Phát hiện có người : Value = 1");
    while(digitalRead(motion)== 1)delay(10);
  }else {
    Serial.println("Không phát hiện có người : Value = 0");
    while(digitalRead(motion)== 0)delay(10);
  }
}