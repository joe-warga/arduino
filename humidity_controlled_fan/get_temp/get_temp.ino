
// function: switch a 120V controller
// test flashing an LED

#define in_plus 12 //defines the variable throughout the prog as the interger
#define sense A1 //defines the variable throughout the prog as the pin callout
#define led 13 //define pin of led as 13

//___________________________________________________
// int defines a variable as an integer
int d = 1000;  // delay time in millisec (3000 = 3 sec)
float set_point = 55.0;
// SEN-09569-HIH-4030
float offset = 0.958; // zero offset 0.958 V
float slope = 0.03068; // slope 30.680 mV/%RH
// conversion to Relative Humidity (RH): (VOUT - offset)/slope
//___________________________________________________

// void is used in function declarations, indicates that the function returns nothing
// setup() called when sketch starts, initializes variables, pinmode, libraries. Runs at power-on of board
void setup()
{
  // serial used for communication between the board and computer
  Serial.begin(9600); // serial begin sets the data rate in bits/sec (baud) (300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200)
  pinMode(led, OUTPUT);
  pinMode(in_plus, OUTPUT); // pinMode(pin, mode) configures a pin to act as either input or output; mode = (INPUT, OUTPUT, INPUT_PULLUP)
}

// void is used in function declarations, indicates that the function returns nothing
// loop called after setup, to loop consecutively. Use it such that the board does something constantly
void loop() {
  int sensor_value = analogRead(sense); // fetch the analog signal
  float voltage = sensor_value * (5.0/1023); // convert to voltage
  float rh = (voltage - offset) / slope; // conversion to Relative Humidity: (VOUT - offset)/slope
  //Serial.println(sensor_value); // output the sensor value
  //Serial.println(voltage); // output the voltage
  Serial.println(rh); // output the humidity
  
  if (rh > (set_point))
  {
    digitalWrite(in_plus,HIGH);
    digitalWrite(led,LOW);
    //Serial.println(" humid, fan on");
  }
  if (rh < (set_point))
  {
    digitalWrite(in_plus,LOW); 
    digitalWrite(led,HIGH);
    //Serial.println(" not that humid, fan off");
  }
  //Serial.print(GetTemp(),1);
  //Serial.println(" degrees C");
  delay(d);
}

double GetTemp(void)
{
  unsigned int wADC;
  double t;

  // The internal temperature has to be used
  // with the internal reference of 1.1V.
  // Channel 8 can not be selected with
  // the analogRead function yet.

  // Set the internal reference and mux.
  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
  ADCSRA |= _BV(ADEN);  // enable the ADC

  delay(20);            // wait for voltages to become stable.

  ADCSRA |= _BV(ADSC);  // Start the ADC

  // Detect end-of-conversion
  while (bit_is_set(ADCSRA,ADSC));

  // Reading register "ADCW" takes care of how to read ADCL and ADCH.
  wADC = ADCW;

  // The offset of 324.31 could be wrong. It is just an indication.
  t = (wADC - 324.31 ) / 1.22;

  // The returned temperature is in degrees Celcius.
  return (t);
}
