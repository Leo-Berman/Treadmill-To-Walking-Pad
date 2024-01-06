int TREADMILL_MOTOR_PIN = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(TREADMILL_MOTOR_PIN, OUTPUT);
  analogWrite(TREADMILL_MOTOR_PIN, 0);
  // delay(100);
  Serial.begin(9600);
  while (!Serial)
  {
      // do nothing
  };
  Serial.println("I am in setup");
  
  // analogWrite(TREADMILL_MOTOR_PIN, val);
  timed_run(3, 100);
  timed_run(3, 50);
  // timed_run(3, 0);
  run(25);
  // Serial.println("I have exited the speed control program");
}

void loop() {
}

void run(int percent_power) {
  int val = map(percent_power, 0, 100, 0, 255);
  analogWrite(TREADMILL_MOTOR_PIN, val);
}

void timed_run(int seconds, int percent_power) {
  int val = map(percent_power, 0, 100, 0, 255);
  int start_time = millis();
  int end_time = start_time;
  int run_time = seconds*1000;
  analogWrite(TREADMILL_MOTOR_PIN, val);
  while ((end_time - start_time) <=run_time) { // do this loop for up to 1000ms
    end_time = millis();
    Serial.println(end_time);
  }
  analogWrite(TREADMILL_MOTOR_PIN, 0);
}