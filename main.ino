int ledPins[] = {8, 9, 10, 11};
int inputPins[] = {2, 3, 4, 5};
int addPin = 6;
int multPin = 7;
int clockPin = 13;
byte regA = 0b0000;
byte regB = 0b0000;
byte result = 0b0000;
bool operationSelected = false;
bool regAInput = true;

void setup() {
  for (int i = 0; i < 4; i++) pinMode(ledPins[i], OUTPUT);
  for (int i = 0; i < 4; i++) pinMode(inputPins[i], INPUT);
  pinMode(addPin, INPUT);
  pinMode(multPin, INPUT);
  pinMode(clockPin, INPUT);
  Serial.begin(9600); // For debugging
}

void loop() {
  if (digitalRead(clockPin) == HIGH) {
    delay(50); // Debounce

    if (regAInput) {
      regA = readBinaryInput();
      Serial.print("Reg A: ");
      Serial.println(regA, BIN);
      displayResult(regA);
      delay(1000);
      regAInput = false;
    } else {
      regB = readBinaryInput();
      Serial.print("Reg B: ");
      Serial.println(regB, BIN);
      displayResult(regB);
      delay(1000);

      if (digitalRead(addPin) == HIGH) {
        result = regA + regB;
        Serial.println("Adding...");
      } else if (digitalRead(multPin) == HIGH) {
        result = regA * regB;
        Serial.println("Multiplying...");
      }

      result = result & 0b1111; // Ensure 4-bit result
      Serial.print("Result: ");
      Serial.println(result, BIN);

      displayResult(result);
      delay(2000);

      regAInput = true; // Reset for next operation
    }
  }
}

byte readBinaryInput() {
  byte value = 0;
  for (int i = 0; i < 4; i++) {
    value |= (digitalRead(inputPins[i]) << i);
  }
  return value;
}

void displayResult(byte value) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], (value >> i) & 0b1);
  }
}
