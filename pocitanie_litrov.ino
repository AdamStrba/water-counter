const int buttonPin = 8;//vstup tlacitka
const int ledPin = 13;//doska LED
const int ledPinRed = 12;//LED tlacidla, vystup impulzov
const int pulsePin = 2;//citac impulzov
unsigned long previousMillis = 0;
unsigned long previousMillisPulse = 0;
const long interval = 1000;
bool buttonState = false;//aktualny stav tlacidla
bool lastButtonState = false;//posledny stav tlacidla
bool lastpuls = false;//posledny stav pulsu
bool pulse = false;//aktualny stav pulsu
int buttonStatex;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;//oseternie casu debounce
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
    }//blikanie LED diody, je interval medzi jednodlivimi bliknutiami
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
      }
    }
  }//toto je odskok pre tlacitko s pouzitim debouce
  lastButtonState = buttonState;

  unsigned long currentMillis2 = millis();
  if (pulse == true) {
    digitalWrite(ledPinRed, HIGH);


    if (currentMillis2 - previousMillisPulse >= 1000) {
      previousMillisPulse = currentMillis2;

      digitalWrite(ledPinRed, LOW);

      pulse = false;
    }
  } else {
    previousMillisPulse = currentMillis2;
  }
  //citac pulsov
  bool puls = digitalRead(pulsePin);
  if (puls != lastpuls) {
    if (puls == HIGH) {
      litreCount++;
      Serial.print("Počet litrov: ");
      Serial.println(litreCount);
    }
  }
  lastpuls = puls;
}
