/** A sanity test to make sure the button works.
  * When the button is pressed, the built-in LED will turn on.
  *
  */

const int led = 13; // blink built in LED
const int buttonPin = 6;
int buttonVal = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT); 
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

// put your main code here, to run repeatedly
void loop() {
  int buttonVal = digitalRead(buttonPin);
  if (buttonVal == HIGH) {
     digitalWrite(led, HIGH); 
  } else {
    digitalWrite(led, LOW);
  }
 
}

