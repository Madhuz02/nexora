int buzzer = 9;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(buzzer, HIGH);  // ON
  delay(500);                 
  digitalWrite(buzzer, LOW);   // OFF
  delay(100);                 
}