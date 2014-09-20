
//use pins a1 and a2 for temp sensors.
//6V power supply  2 Amps
//temp sensor data sheet http://ww1.microchip.com/downloads/en/DeviceDoc/21942e.pdf
//mossfet (switch) max voltage is 20V look here for specs : http://www.vishay.com/docs/65154/si4204dy.pdf
//can change temperature set points in test by pressing upload. the set point will change

#define switch1 9 // #define constant_name value // sets a constant that is compiled to the value later
#define switch2 10

//___________________________________________________
// int defines a variable as an integer
int dtime = 3000;  // delay time in millisec (3000 = 3 sec)
int setpt1 = 30; // set pt heater 1
int setpt2 = 30; // set point heater 2
int hyst = 1; // above or below set point before heater is activated
//___________________________________________________

// void is used in function declarations, indicates that the function returns nothing
// setup() called when sketch starts, initializes variables, pinmode, libraries. Runs at power-on of board
void setup()
{
// serial used for communication between the board and computer
  Serial.begin(9600); // serial begin sets the data rate in bits/sec (baud) (300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200)
  pinMode(switch1, OUTPUT); // pinMode(pin, mode) configures a pin to act as either input or output; mode = (INPUT, OUTPUT, INPUT_PULLUP)
  pinMode(switch2, OUTPUT); // pinMode(pin, mode) configures a pin to act as either input or output; mode = (INPUT, OUTPUT, INPUT_PULLUP)
}

// void is used in function declarations, indicates that the function returns nothing
// loop called after setup, to loop consecutively. Use it such that the board does something constantly
void loop() {
  //get the analog signal
  int sensorValue0 = analogRead(A1); // analogRead(pin) reads the pin
  int sensorValue1 = analogRead(A2); // analogRead(pin) reads the pin

  //convert to voltage
  float voltage0 = sensorValue0 * (5.0 /1023); // do some math
  float voltage1 = sensorValue1 * (5.0 /1023); // do some math

  //convert voltage to temperature in C
  float Const = -50.00 ; // float defines variable as float
  float temp1 = voltage0 * 100 + Const;
  float temp2 = voltage1 * 100 + Const;

  //sets temp set point in C
  if (temp1 > (setpt1 + hyst)) // test if temperature greater than window defined
  {
    digitalWrite(switch1,LOW); // digitalWrite(pin, value) this turns off the pin
  }
  if (temp1 <(setpt1 - hyst)) // test if temperature lest than window defined
  {
    digitalWrite(switch1,HIGH); // digitalWrite(pin, value) this turns on the pin
    Serial.println("heating 1"); // Serial.println("string"), prints to serial output
  }

// same loop for second line
  if (temp2 > (setpt2 + hyst))
  {
    digitalWrite(switch2,LOW);
  }
  if (temp2 < (setpt2 - hyst))
  {
    digitalWrite(switch2,HIGH); 
    Serial.println("heating 2");
  }

  Serial.print(temp1); // Serial.print(variable), prints the variable output
  Serial.print(',');
  Serial.print(temp2);

  Serial.println(' '); //println('string'), Prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').

  delay(dtime); // this defines the time between loop iterations
}


