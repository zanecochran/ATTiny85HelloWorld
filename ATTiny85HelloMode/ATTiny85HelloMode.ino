// Hello World for Programming an ATTiny85
//Cameron Acton

//Pin Assignment
const int led = 1;
const int but = 0;

int butState;
int prevState;

int state = 0; //Variable which controls the state of the circuit

long sT = millis(); //Variable to track the "starting time" a timer
boolean lit = true; //Controlls the lit status of an led in the blinking state

void setup() {
  pinMode(led, OUTPUT);
  pinMode(but, INPUT);
}

void loop() {
  butState = digitalRead(but);

  //Used for debouncing user button inputs and changing states
  if (butState == 1 && prevState == 0) {
    delay(10); //Used to debounce hardware
    state ++;
    if (state > 2) {
      state = 0;
    }
  }
  
  prevState = butState;

  //FSM that controlls the "state" of the LED
  switch (state) {
    case 0: //OFF STATE//
      digitalWrite(led, LOW);
      break;
    case 1: //ON STATE//
      digitalWrite(led, HIGH);
      break;
    case 2: //BLINKING STATE//
      //Timer
      if (millis() - sT > 100) {
        if (lit) {
          lit = !lit;
        } else {
          lit = !lit;
        }
        sT = millis();
      }

      //Used to control status of LED
      if (lit) {
        digitalWrite(led, HIGH);
      } else {
        digitalWrite(led, LOW);
      }
      break;
  }
}
