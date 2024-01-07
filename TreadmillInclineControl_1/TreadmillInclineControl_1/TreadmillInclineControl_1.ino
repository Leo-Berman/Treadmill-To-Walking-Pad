int IN1 = 12;
int IN2 = 7;

void setup() {
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    int command = Serial.parseInt();
    
    if (command == 1){
      enable_k1();
    }
    
    else if (command == 2){
      enable_k2();
    }
    
    else if(command == 3){
      off();
    }
    else{
      ;
    }
   }

}

void enable_k1(){
  digitalWrite(IN1,HIGH);
}

void enable_k2(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}

void off(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}