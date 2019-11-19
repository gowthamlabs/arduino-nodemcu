int inPin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); 
  digitalWrite(LED_BUILTIN, LOW); 
  digitalWrite(LED_BUILTIN, HIGH); 
  digitalWrite(LED_BUILTIN, LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(LED_BUILTIN, digitalRead(inPin));
}
