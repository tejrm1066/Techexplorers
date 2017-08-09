int rLed = 13;  // declare  variable rLed and give it a value of 13. this variable will be used for pinMode setup
int bState = 0;  // declare  variable bState and give it an initial value of 0. The button state will be 0 if the button switch is not pressed and 1 if buttonswitch pressed
int buttonSwitch = 3;  // declare  variable button Switch and give it value = pin # that the switch is connected to
void setup() {
  pinMode(buttonSwitch, INPUT); 
  pinMode(rLed, OUTPUT);
}

void loop() {
 bState = digitalRead(buttonSwitch); // digitalRead looks at the voltage on pin 3 (buttonSwitch) and if it reads no voltage 
 //(when the button switch is not pressed),bstate will be given a value of 0. If there is voltage (when the button IS pressed)
 //bstate will be given a value of 1.
  if (bState == 1) {  // an if statement will execute the lines of code between the curly braces { } 
    //when the statement in brackets,( ), is true. If the button is being pressed (bstate=1) the led will turn on
    digitalWrite(13, HIGH); //
  }
  else if(bState == 0) {  //If the button is not being pressed (bstate=0) the led will turn off
    digitalWrite(13, LOW);
  }
}
