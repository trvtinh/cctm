int sensor = 23 ;

void setup(){
  Serial.begin(115200);
  pinMode(sensor , INPUT_PULLUP);
}

void loop(){
  int val = digitalRead(sensor);
  if (val == 1){
    Serial.print("Hall Sensor Value : 1  | Mở cửa ");
  }else {
    Serial.print("Hall Sensor Value : 0  | Đóng cửa ");
  }
  delay(500);
}