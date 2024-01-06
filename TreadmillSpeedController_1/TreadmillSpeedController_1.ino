int speed = 0;
int outputpin = 9;
int val = "-1";
void setup() {

  pinMode(outputpin, OUTPUT);

  Serial.begin(9600);    //start serial communication @9600 bps

  }

void loop(){
  
  if(Serial.available()){  //id data is available to read
    val = Serial.parseInt(); 
    if ((val >= -1) & (val <=100)){
      if (val == -1){
        Serial.println("A");
        run(0);
      }
      else{
        run(val);
        Serial.println("Set");
      }
    }
  }
}

void run(int percent_power) {
  int val = map(percent_power, 0, 100, 0, 255);
  analogWrite(outputpin, val);
}

void timed_run(int seconds, int percent_power) {
  int val = map(percent_power, 0, 100, 0, 255);
  int start_time = millis();
  int end_time = start_time;
  int run_time = seconds*1000;
  analogWrite(outputpin, val);
  while ((end_time - start_time) <=run_time) { // do this loop for up to 1000ms
    end_time = millis();
    Serial.println(end_time);
  }
  analogWrite(outputpin, 0);
}