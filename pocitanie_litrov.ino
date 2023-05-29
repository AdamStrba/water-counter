const int buttonPin = 8;
const int ledPin = 13;
const int ledPinRed = 12;
const int pulsePin = 2;
unsigned long previousMillis = 0;
unsigned long previousMillisPulse = 0;
const long interval = 1000;
bool buttonState = false;
bool lastButtonState = false;
bool lastpuls = false;
bool pulse = false;
int buttonStatex;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int litreCount = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPinRed, OUTPUT);
  pinMode(pulsePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (digitalRead(ledPin) == LOW) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }

  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (buttonState != buttonStatex) {
      buttonStatex = buttonState;

      if (buttonState == LOW) {
        pulse = true;
        //itreCount++;
        //erial.print("Počet litrov: ");
        //erial.println(litreCount);
      }
    }
  }
  lastButtonState = buttonState;

  unsigned long currentMillis2 = millis();
  if (pulse == true) {
    digitalWrite(ledPinRed, HIGH);


      litreCount++;
      Serial.print("Počet litrov: ");
      Serial.println(litreCount);
    }

    if (currentMillis2 - previousMillisPulse >= 1000) {
      previousMillisPulse = currentMillis2;

      digitalWrite(ledPinRed, LOW);

      pulse = false;
    }
  } else {
    previousMillisPulse = currentMillis2;
  }
  //ciatac pulzov
  bool puls = digitalRead(pulsePin);


  if (puls != lastpuls) {
    if (puls == HIGH) {
  }
  lastpuls = puls;
  
}
