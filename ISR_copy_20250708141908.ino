const int buttonPin = 35;             // GPIO34 (input-only)
volatile bool eventFlag = false;      // ISR flag

// ISR: runs when button is pressed
void IRAM_ATTR handleInterrupt() {
  eventFlag = true;
}

void setup() {
  Serial.begin(115200);               // Start Serial Monitor
  delay(1000);                        // Wait a bit for Serial Monitor to connect

  pinMode(buttonPin, INPUT);          // GPIO 34 is input-only
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, FALLING); // Trigger on button press
}

void loop() {
  if (eventFlag) {
    eventFlag = false;               // Clear the flag
    Serial.println("✅ Button on GPIO was pressed (ISR triggered)");
  }
}

