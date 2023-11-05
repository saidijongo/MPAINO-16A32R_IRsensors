const int totalLEDs = 32;
int ledPins[totalLEDs];
int sensor1Pin = 14;
int sensor2Pin = 15; 

void setup() {
  for (int pin = 0; pin < totalLEDs; pin++) {
    ledPins[pin] = 54 + pin;
    pinMode(ledPins[pin], OUTPUT);
  }

  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
}

void loop() {
  int sensor1State = digitalRead(sensor1Pin);

  if (sensor1State == HIGH) {
    // Sensor 1 is interrupted, blink LEDs
    for (int pin = 0; pin < totalLEDs; pin++) {
      digitalWrite(ledPins[pin], HIGH);
    }
  } else {
    // Sensor 1 is not interrupted, turn off LEDs
    for (int pin = 0; pin < totalLEDs; pin++) {
      digitalWrite(ledPins[pin], LOW);
    }
  }

  int sensor2State = digitalRead(sensor2Pin);

  if (sensor2State == HIGH) {
    // Sensor 2 is interrupted, turn off blinking LEDs
    for (int pin = 0; pin < totalLEDs; pin++) {
      digitalWrite(ledPins[pin], LOW);
    }
  }
}
