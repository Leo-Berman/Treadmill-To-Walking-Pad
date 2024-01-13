/* Leo Berman and Liam Coleman
leo.berman@temple.edu
liam@megster.com
1/8/2024
*/
/* Declare Global Variables*/
int speed_pin = 9; // Output PWM pin that controls thte speed of the treadmill

// Digital output pins for controlling the relay board
int IN1 = 12; // IN1
int IN2 = 7; // IN2

// Initialize arduino
void setup() {

  // Set the pins controlling speed and incline logic to be output
  pinMode(speed_pin, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);


  Serial.begin(9600); // Begin communication with serial input

  analogWrite(speed_pin,0); // Set the treadmill to off
  off(); // initialize incline to static
  }

// Main loop
void loop(){

  // When input comes in
  if(Serial.available()){  //id data is available to read
      
    //Serial.println("Serial Available"); // Debug
    
    // Parsing serial input
    int input_command = Serial.parseInt();
    
    
    /* Debugging
    Serial.println(parses[0]);
    Serial.println(parses[1].toInt());
    Serial.print("Command Type = ");
    Serial.println(parses[0]);
    Serial.print("Number = ");
    Serial.println(parses[1].toInt());
    */

    // Checks if incoming statement is speed(S) or incline(I) related
    if (input_command <= 100 && input_command >= 0){
    run(input_command);
    }
    else if (input_command > 100 && input_command<=103){
      change_incline(input_command-100); 
    }
    else {
      //Serial.println("In Else"); // Debugging
      run(0); // Stops the treadmill in case of extraneous case
    }
  }
}

// Incline logic  to select wich gates should be open
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

// Disable gate 2 and enable gate 1
void enable_k1(){
  digitalWrite(IN1,LOW);
}

// Enable gates 1 and 2
void enable_k2(){
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

// Disable gates 1 and 2
void off(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
}

// controls treadmill speed
void run(int percent_power) {

  int val = map(percent_power, 0, 100, 0, 255); // maps scale from 0 to 100 to full scale of arduino output (0 to 255)
  analogWrite(speed_pin, val); // Writes the voltage value to the arduino speed output pin using pwm
}

 void timed_run(int seconds, int percent_power) {
   int val = map(percent_power, 0, 100, 0, 255);// maps scale from 0 to 100 to full scale of arduino output (0 to 255)
  

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
