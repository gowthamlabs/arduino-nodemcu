const int ldrPin = A1

void setup() {
  // put your setup code here, to run once:

  // To enable serial monitor
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrStatus = analogRead(ldrPin)

  Serial.print("LDR output status");
  Serial.println(ldrStatus);
}
