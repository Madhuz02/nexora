int trigPin = 7;
int echoPin = 10;
int ledPin = 6;
int buzzerPin = 9;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo
  duration = pulseIn(echoPin, HIGH);

  // Convert to cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // BIN FULL
  if(distance < 10) {

    Serial.println("Bin is Full");

    digitalWrite(ledPin, HIGH);

    tone(buzzerPin, 1000);  // 1000 Hz sound
  }

  // BIN HALF
  else if(distance >= 10 && distance <= 20) {

    Serial.println("Alert Going to Full");

    digitalWrite(ledPin, HIGH);

    tone(buzzerPin, 500);   // Slower warning sound
    delay(200);
    noTone(buzzerPin);
  }

  // BIN EMPTY
  else {

    Serial.println("Bin is Empty");

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  Serial.println("----------------------");
  delay(1000);
}