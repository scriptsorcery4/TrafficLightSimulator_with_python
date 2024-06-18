const int ledPin1 = 4; // Pin where the first LED is connected
const int ledPin2 = 3; // Pin where the second LED is connected
const int ledPin3 = 2; // Pin where the third LED is connected

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  if (Serial.available() > 0) { // Check if there is data available to read
    String command = Serial.readStringUntil('\n'); // Read the incoming string until newline character
    if (command.length() == 5 && command[1] == ',' && command[3] == ',') { // Check if the command format is correct
      int state1 = command[0] - '0'; // Convert char to int
      int state2 = command[2] - '0'; // Convert char to int
      int state3 = command[4] - '0'; // Convert char to int

      digitalWrite(ledPin1, state1 == 1 ? HIGH : LOW); // Set LED1 state
      digitalWrite(ledPin2, state2 == 1 ? HIGH : LOW); // Set LED2 state
      digitalWrite(ledPin3, state3 == 1 ? HIGH : LOW); // Set LED3 state
    }
  }
}
