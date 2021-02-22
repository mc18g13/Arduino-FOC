#include "../hardware_api.h" 

#if defined(__arm__) && defined(CORE_TEENSY)

//  configure High PWM frequency
void _setHighFrequency(const long freq, const int pin){
  analogWrite(pin, 0);
  analogWriteFrequency(pin, freq); 
}


// function setting the high pwm frequency to the supplied pins
// - Stepper motor - 2PWM setting
// - hardware speciffic
void _configure2PWM(long pwm_frequency, const int pinA, const int pinB) {
  if(!pwm_frequency || !_isset(pwm_frequency) ) pwm_frequency = 50000; // default frequency 50khz
  else pwm_frequency = _constrain(pwm_frequency, 0, 50000); // constrain to 50kHz max
  _setHighFrequency(pwm_frequency, pinA);
  _setHighFrequency(pwm_frequency, pinB);
}

// function setting the high pwm frequency to the supplied pins
// - BLDC motor - 3PWM setting
// - hardware speciffic
void _configure3PWM(long pwm_frequency,const int pinA, const int pinB, const int pinC) {
  if(!pwm_frequency || !_isset(pwm_frequency) ) pwm_frequency = 50000; // default frequency 50khz
  else pwm_frequency = _constrain(pwm_frequency, 0, 50000); // constrain to 50kHz max
  _setHighFrequency(pwm_frequency, pinA);
  _setHighFrequency(pwm_frequency, pinB);
  _setHighFrequency(pwm_frequency, pinC);
}

// function setting the high pwm frequency to the supplied pins
// - Stepper motor - 4PWM setting
// - hardware speciffic
void _configure4PWM(long pwm_frequency,const int pinA, const int pinB, const int pinC, const int pinD) {
  if(!pwm_frequency || !_isset(pwm_frequency) ) pwm_frequency = 50000; // default frequency 50khz
  else pwm_frequency = _constrain(pwm_frequency, 0, 50000); // constrain to 50kHz max
  _setHighFrequency(pwm_frequency, pinA);
  _setHighFrequency(pwm_frequency, pinB);
  _setHighFrequency(pwm_frequency, pinC);
  _setHighFrequency(pwm_frequency, pinD);
}

// function setting the pwm duty cycle to the hardware 
// - Stepper motor - 2PWM setting
// - hardware speciffic
void _writeDutyCycle2PWM(float dc_a,  float dc_b, int pinA, int pinB){
  // transform duty cycle from [0,1] to [0,255]
  _analogWriteUnitInterval(pinA, dc_a);
  _analogWriteUnitInterval(pinB, dc_b);
}
// function setting the pwm duty cycle to the hardware
// - BLDC motor - 3PWM setting
// - hardware speciffic
void _writeDutyCycle3PWM(float dc_a,  float dc_b, float dc_c, int pinA, int pinB, int pinC){
  // transform duty cycle from [0,1] to [0,255]
  _analogWriteUnitInterval(pinA, dc_a);
  _analogWriteUnitInterval(pinB, dc_b);
  _analogWriteUnitInterval(pinC, dc_c);
}

// function setting the pwm duty cycle to the hardware
// - Stepper motor - 4PWM setting
// - hardware speciffic
void _writeDutyCycle4PWM(float dc_1a,  float dc_1b, float dc_2a, float dc_2b, int pin1A, int pin1B, int pin2A, int pin2B){
  // transform duty cycle from [0,1] to [0,255]
  _analogWriteUnitInterval(pin1A, dc_1a);
  _analogWriteUnitInterval(pin1B, dc_1b);
  _analogWriteUnitInterval(pin2A, dc_2a);
  _analogWriteUnitInterval(pin2B, dc_2b);
}


// Configuring PWM frequency, resolution and alignment
// - BLDC driver - 6PWM setting
// - hardware specific
int _configure6PWM(long pwm_frequency, float dead_zone, const int pinA_h, const int pinA_l,  const int pinB_h, const int pinB_l, const int pinC_h, const int pinC_l){
  if(!pwm_frequency || !_isset(pwm_frequency)) pwm_frequency = 50000; // default frequency 50khz
  else pwm_frequency = _constrain(pwm_frequency, 0, 50000); // constrain to 50kHz max
  _setHighFrequency(pwm_frequency, pinA_h);
  _setHighFrequency(pwm_frequency, pinA_l);
  _setHighFrequency(pwm_frequency, pinB_h);
  _setHighFrequency(pwm_frequency, pinB_l);
  _setHighFrequency(pwm_frequency, pinC_h);
  _setHighFrequency(pwm_frequency, pinC_l);
}

// Function setting the duty cycle to the pwm pin (ex. _analogWriteUnitInterval())
// - BLDC driver - 6PWM setting
// - hardware specific
void _writeDutyCycle6PWM(float dc_a, float dc_b, float dc_c, float dead_zone, int pinA_h, int pinA_l, int pinB_h, int pinB_l, int pinC_h, int pinC_l){
  // transform duty cycle from [0,1] to [0,255]
  _analogWriteUnitInterval(pinA_h, dc_a);
  _analogWriteUnitInterval(pinA_l, dc_a);
  _analogWriteUnitInterval(pinB_h, dc_b);
  _analogWriteUnitInterval(pinB_l, dc_b);
  _analogWriteUnitInterval(pinC_h, dc_c);
  _analogWriteUnitInterval(pinC_l, dc_c);
}

#endif
