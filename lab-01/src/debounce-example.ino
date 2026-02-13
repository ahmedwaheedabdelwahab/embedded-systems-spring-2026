void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Configure pin 2 as an input with the internal pull-up resistor enabled
  pinMode(2, INPUT_PULLUP);
  // Configure pin 13 (built-in LED) as an output
  pinMode(13, OUTPUT);
}

void loop() {
  // Read the pushbutton value into a variable
  int sensorVal = digitalRead(2);

  // Print out the value of the pushbutton
  Serial.println(sensorVal);

  /* * Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
   * HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
   * button's pressed, and off when it's not:
   */
  if (debounce(2)) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}

/**
 * Custom debounce function to ensure a stable reading.
 * It waits for the signal to remain constant for 10 consecutive milliseconds.
 */
boolean debounce(int pin) {
  boolean state;
  boolean previousState;

  previousState = digitalRead(pin);

  for (int i = 0; i < 10; i++) {
    delay(1); // Wait for 1 millisecond
    state = digitalRead(pin);

    if (state != previousState) {
      i = 0; // reset the iterative counter
      previousState = state; // set the previous state
    }
  }

  return state;
}
