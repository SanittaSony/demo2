const int ledPin = 4;     // GPIO4 connected to LED
const int switchPin = 35; // GPIO35 connected to push-button (with external pull-up)

void setup() {
  pinMode(ledPin, OUTPUT);        // Set LED pin as output
  pinMode(switchPin, INPUT);      // Set switch pin as input (external pull-up required)
}

void loop() {
  int switchState = digitalRead(switchPin); // Read the state of the switch

  if (switchState == LOW) {
    digitalWrite(ledPin, HIGH); // Turn ON LED if button is pressed (LOW)
    delay(100)
  } else {
    digitalWrite(ledPin, LOW);  // Turn OFF LED if button is released (HIGH)
    delay(100)
  }
}
