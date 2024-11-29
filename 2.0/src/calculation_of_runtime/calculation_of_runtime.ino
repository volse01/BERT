const int buttonPin = 2;
const int pumpPins[] = {3, 5, 6};
const unsigned long pumpTime = 1000; //in ms

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);//pin setup for button needs to pass 5v to pin 2
  for (int i = 0; i < 3; i++) {
    pinMode(pumpPins[i], OUTPUT);// pin setup for pumps
  }
  void pump(int pin, unsigned long time) { // pump function 

    digitalWrite(pin, HIGH); //pump on
    delay(time);
    digitalWrite(pin, LOW); //pump off
  }
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    for (int i = 0; i < 3; i++) {
      pump(pumpPins[i], pumpTime); //pumps will work after each other  
    }
  }
}
