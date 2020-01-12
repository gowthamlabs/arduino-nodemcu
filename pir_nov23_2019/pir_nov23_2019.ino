#define pirPin 8

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pirPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(pirPin) == HIGH) {
    Serial.print(digitalRead(pirPin));
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    Serial.print(digitalRead(pirPin));
    digitalWrite(LED_BUILTIN, LOW);
  }
  
}
