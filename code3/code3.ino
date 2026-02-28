int trigPin = 8;
int echoPin = 10;
int led = 7;
int buzzer = 9;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // BIN FULL
  if(distance == 0) {
    Serial.println("Sensor Error");
}

else if(distance < 10) {

    Serial.println("Bin is Full");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  // BIN HALF FULL
  else if(distance >= 10 && distance <= 20) {

    Serial.println("Alert Going to Full");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
  }

  // BIN EMPTY
  else {

    Serial.println("Bin is Empty");
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }

  Serial.println("--------------------");
  delay(1000);
}