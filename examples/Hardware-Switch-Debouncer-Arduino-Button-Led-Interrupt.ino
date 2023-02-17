/* A simple example of a hardware switch debouncer with an interrupt.
Button should be connected to GND and via switch debouncer into Arduino pin 2 or any interrupt pin.
Diagram of how to connect a debouncer with an Arduino: https://bit.ly/HSD-ARD */

/* Pin usable for interrupt from button 
connected via hardware switch debouncer */
#define Button1    10

volatile bool PressButton1State = false;
volatile bool LedState = false;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(Button1, INPUT_PULLUP);
  
  /* Trigger when button pressed, but not when released */
  attachInterrupt(digitalPinToInterrupt(Button1), InterruptButton1, RISING); 
}

void loop() 
{ 
  if(PressButton1State == true)
  {
    /* Toggle Led state */
    LedState = !LedState;
    digitalWrite(LED_BUILTIN, LedState);
      
    PressButton1State = false;     
  }
}

void InterruptButton1(void)
{
  /* Each time the button is pressed, set the flag */
  PressButton1State = true;
}
