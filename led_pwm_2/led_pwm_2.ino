
// test flashing an LED

#define led 13 // #define constant_name value // sets a constant that is compiled to the value later

//___________________________________________________
// int defines a variable as an integer
int period = 1000;  // delay time in microsec (3,000,000 = 3 sec)
int pwm = 1;
int d = period * pwm / 100;
int dtime = period - d;
int i = 0;
int steplength = 10000;
int max_pwm = 30;
//___________________________________________________

// void is used in function declarations, indicates that the function returns nothing
// setup() called when sketch starts, initializes variables, pinmode, libraries. Runs at power-on of board
void setup()
{
// serial used for communication between the board and computer
  Serial.begin(9600); // serial begin sets the data rate in bits/sec (baud) (300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200)
  pinMode(led, OUTPUT); // pinMode(pin, mode) configures a pin to act as either input or output; mode = (INPUT, OUTPUT, INPUT_PULLUP)
}

// void is used in function declarations, indicates that the function returns nothing
// loop called after setup, to loop consecutively. Use it such that the board does something constantly
void loop() {
  if (i < steplength)
  {
    if (i % 40 == 0)
    {
      pwm = pwm + 1;
      d = period * pwm / 100;
      dtime = period - d;
      Serial.print(sin(pwm*1.0/max_pwm));
      Serial.println(' ');
    }
    delayMicroseconds(dtime); // this defines the time between loop iterations
    digitalWrite(led,HIGH);
    delayMicroseconds(d);
    digitalWrite(led,LOW);
  }
  if (pwm > max_pwm)
  {
    pwm = 0;
  }
  if (i > steplength)
  {
    i = 0;
  }
  i = i + 1;
}
