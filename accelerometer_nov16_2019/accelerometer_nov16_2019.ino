const int x_in = A1;
const int y_in = A2;
const int z_in = A3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  if(analogRead(x_in) > 350) {
    Serial.println("move forward");
  } else if(analogRead(x_in) < 330) {
    Serial.println("move backward");
  } else if(analogRead(y_in) > 350 ) {
    Serial.println("move left");
  } else if(analogRead(y_in) < 320 ) {
    Serial.println("move right");
  } else {
     Serial.println("stop");
  }
}
