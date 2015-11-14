
int timer0_count=0;

// Millisecond timer
void timer0_init()
{
  OCR0A = 0xFF; // just some value
  TIMSK0 |= _BV(OCIE0A);
}

void timer1_init(int ms)
{
  // disable all interrupts
  noInterrupts();

  uint16_t scale = uint16_t( (float)ms * 46.875);

  // Timer/Counter Control Register. The pre-scaler can be configured here.
  TCCR1A = 0;
  TCCR1B = _BV(WGM12); // CTC mode
  TCCR1B |= _BV(CS12); // 256 prescaler

  // Timer/Counter Interrupt Flag Register. Indicates a pending timer interrupt.
  //TIFR1 = 0;

  // Timer/Counter Register. The actual timer value is stored here.
  TCNT1 = 0;

  // Output Compare Register
  // 12,000,000Hz/256 = 46875; 46875/1hz = 46875
  OCR1A = scale; // Compare match register 12Mhz/256/1Hz
  //OCR1B = 0xB7;
  // Input Capture Register (only for 16bit timer)
  //ICR1 = 0;

  // Timer/Counter Interrupt Mask Register. To enable/disable timer interrupts.
  TIMSK1 = _BV(OCIE1A);

  // enable all interrupts
  interrupts();
}

void enablePinInterupt(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{
  if(digitalRead(buttonPin)) {  button_press(); }
  //if(digitalRead(switchPin)) { switch_change(); }
}

// Timer0 compare interrupt service routine
SIGNAL(TIMER0_COMPA_vect)
{
  // Toggle LED
  if(timer0_count++>1000)
  {
    timer0_count=0;
    digitalWrite(13, digitalRead(13)^1);
  }
}

// Timer1 compare interrupt service routine
SIGNAL(TIMER1_COMPA_vect)
{
  switch_it();
}


