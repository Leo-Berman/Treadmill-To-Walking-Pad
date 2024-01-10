/* Leo Berman and Liam Coleman
leo.berman@temple.edu
liam@megster.com
1/8/2024
*/
/* Declare Global Variables*/
int speed_pin = 9; // Output PWM pin that controls thte speed of the treadmill
int output_pin = 9;
int val = 0;
int IN1 = 12;
int IN2 = 7;

void setup() {

  pinMode(output_pin, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600); //start serial communication @9600 bps
  off();
  }

void loop(){
  
  if(Serial.available()){ //id data is available to read
    Serial.println("Serial Available");
    String input_command = Serial.readString();
    String parses[2];
    int index = input_command.indexOf(' ');
    parses[0] = input_command.substring(0,index);
    parses[1] = (input_command.substring(index+1));
    Serial.println(parses[0]);
    Serial.println(parses[1].toInt());
    /* Debugging
    Serial.print("Command Type = ");
    Serial.println(parses[0]);
    Serial.print("Number = ");
    Serial.println(parses[1].toInt());
    */
    
    if (parses[0] == String("S")){
      run(parses[1].toInt());
      Serial.println("In S");
      /* Debugging
      Serial.print("Speed changed to ");
      Serial.println(parses[1].toInt());
      */
    }
    else if (parses[0] == String("I")){
      Serial.println(parses[1].toInt());
      change_incline(parses[1].toInt());
      
    }
    else {
      Serial.println("In Else");
      run(0);
    }
  }
}
void change_incline(int input){
  if (input == 1){
    enable_k1();
  }
  else if (input == 2){
    enable_k2();
  }
  else if (input ==3){
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
   int val = map(percent_power, 0, 100, 0, 255); // maps scale from 0 to 100 to full scale of arduino output (0 to 255)
  
   // Get initial time stamp to compare
   int start_time = millis(); 
   int end_time = start_time;
   int run_time = seconds*1000;
   analogWrite(speed_pin, val);
   while ((end_time - start_time) <=run_time) { // do this loop for up to 1000ms
     end_time = millis();
     Serial.println(end_time);
   }
   analogWrite(speed_pin, 0);
 }

void timed_run_ver2(int seconds, int percent_power) {
  int val = map(percent_power, 0, 100, 0, 255); // maps scale from 0 to 100 to full scale of arduino output (0 to 255)
    int start_time = millis();   // Get initial time stamp to compare
  int run_time = seconds*1000; // number of time the loop should go for
  int end_time = start_time+run_time; // calculate end_time
  analogWrite(speed_pin, val); // Writes the voltage value to the arduino speed output pin using pwm
  while (millis() < end_time); // Stay in loop until end_time is reached
  analogWrite(speed_pin, 0); // set treadmill speed to 0
}
