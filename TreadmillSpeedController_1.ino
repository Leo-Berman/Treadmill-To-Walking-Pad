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
    if (val == 1){
      Serial.println("U");
      if (speed < 255){
        speed+=5;
      }
    }
    else if (val == 2){
      Serial.println("D");
      if (speed > 0) {
        speed-=5;
      }
    }
    else if (val == -1){
      Serial.println("A");
      speed = 0;
    }
  }
  analogWrite(outputpin,speed);
  
}