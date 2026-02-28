int trigPin = 3;
int echoPin = 4;
int led = 8;
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

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // CONDITION
  if(distance < 10) {        // If bin is full

    digitalWrite(led, HIGH);   // LED ON
    digitalWrite(buzzer, HIGH); // Buzzer ON

  }
  else {

    digitalWrite(led, LOW);     // LED OFF
    digitalWrite(buzzer, LOW);  // Buzzer OFF
  }

  delay(500);
}