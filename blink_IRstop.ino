const int totalLEDs = 32;
int ledPins[totalLEDs];
int sensor1Pin = 14; 
int sensor2Pin = 15; 
bool sensor1Interrupted = false;
bool sensor2Interrupted = false;

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
  int sensor2State = digitalRead(sensor2Pin);

  if (sensor2State == HIGH) {
    // Sensor 2 is interrupted, turn off all LEDs and reset the state
    sensor1Interrupted = false;
    sensor2Interrupted = true;
    for (int pin = 0; pin < totalLEDs; pin++) {
      digitalWrite(ledPins[pin], LOW);
    }
  } else if (sensor1State == HIGH) {
    // Sensor 1 is interrupted, blink LEDs one after another
    sensor1Interrupted = true;
    sensor2Interrupted = false;
    for (int pin = 0; pin < totalLEDs; pin++) {
      digitalWrite(ledPins[pin], HIGH);
      delay(300);
      digitalWrite(ledPins[pin], LOW);
      delay(300);
    }
  } else {
    // No sensors are interrupted, blink all LEDs at once
    sensor1Interrupted = false;
    sensor2Interrupted = false;
    for (int pin = 0; pin < totalLEDs; pin++) {
      digitalWrite(ledPins[pin], HIGH);
    }
    delay(300);  // Blinking interval
    for (int pin = 0; pin < totalLEDs; pin++) {
      digitalWrite(ledPins[pin], LOW);
    }
    delay(300);  // Blinking interval
  }
}
