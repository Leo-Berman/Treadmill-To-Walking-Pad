int speed = 0;
int output_pin = 9;
int val = "-1";
int IN1 = 12;
int IN2 = 7;

void setup() {

  pinMode(output_pin, OUTPUT);

  Serial.begin(9600);    //start serial communication @9600 bps

  }

void loop(){
  
  if(Serial.available()){  //id data is available to read
    Serial.println("Serial Available");
    String input_command = Serial.readString();
    String parses[2];
    int index = input_command.indexOf(' ');
    parses[0] = input_command.substring(0,index-1);
    parses[1] = (input_command.substring(index+1));
    
    /* Debugging
    Serial.print("Command Type = ");
    Serial.println(parses[0]);
    Serial.print("Number = ");
    Serial.println(parses[1].toInt());
    */
    
    if (parses[0] == 'S'){
      run(parses[1].toInt());
      /* Debugging
      Serial.print("Speed changed to ");
      Serial.println(parses[1].toInt());
      */
    }
    else if (parses[1] == 'I'){
      change_incline(parses[1].toInt());
    }
    else {
      run(0);
    }
  }
}
void change_incline(int input){
  if (input == 1){
    enable_k1();
    delay(1000);
    off();
  }
  else if (input == 2){
    enable_k2();
    delay(1000);
    off();
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

void run(int percent_power) {
  int val = map(percent_power, 0, 100, 0, 255);
  analogWrite(output_pin, val);
}

void timed_run(int seconds, int percent_power) {
  int val = map(percent_power, 0, 100, 0, 255);
  int start_time = millis();
  int end_time = start_time;
  int run_time = seconds*1000;
  analogWrite(output_pin, val);
  while ((end_time - start_time) <=run_time) { // do this loop for up to 1000ms
    end_time = millis();
    Serial.println(end_time);
  }
  analogWrite(output_pin, 0);
}