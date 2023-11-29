const int button1Pin = 4;  // the pin number for the first button
const int button2Pin = 2;  // the pin number for the second button
const int led1Pin = 7;     // the pin number for the first LED
const int led2Pin = 8;     // the pin number for the second LED

int button1State = 0;      // variable to store the state of the first button (LOW or HIGH)
int button2State = 0;      // variable to store the state of the second button (LOW or HIGH)
int led1State = LOW;       // variable to store the current state of the first LED
int led2State = LOW;       // variable to store the current state of the second LED

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  // read the state of the first button
  button1State = digitalRead(button1Pin);

  // check if the first button is pressed
  if (button1State == HIGH) {
    // toggle the state of the first LED
    led1State = !led1State;

    // turn off the second LED
    led2State = LOW;

    // update the LEDs based on the current state
    digitalWrite(led1Pin, led1State);
    digitalWrite(led2Pin, led2State);
    
    // wait for a short time to debounce the button
    delay(50);
  }

  // read the state of the second button
  button2State = digitalRead(button2Pin);

  // check if the second button is pressed
  if (button2State == HIGH) {
    // toggle the state of the second LED
    led2State = !led2State;

    // turn off the first LED
    led1State = LOW;

    // update the LEDs based on the current state
    digitalWrite(led1Pin, led1State);
    digitalWrite(led2Pin, led2State);
    
    // wait for a short time to debounce the button
    delay(50);
  }
}
