
// test flashing an LED

#define led 13 // #define constant_name value // sets a constant that is compiled to the value later

//___________________________________________________
// int defines a variable as an integer
int period = 1000;  // delay time in microsec (3,000,000 = 3 sec)
int pwm = 1;
int d = period * pwm / 100;
int dtime = period - d;
int i = 0;
int steplength = 100;
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
    pwm = 1;
    d = period * pwm / 100;
    dtime = period - d;
    delayMicroseconds(dtime); // this defines the time between loop iterations
    digitalWrite(led,HIGH);
    delayMicroseconds(d);
    digitalWrite(led,LOW);
  }
  if (i < steplength*2 && i > steplength)
  {
    pwm = 2;
    d = period * pwm / 100;
    dtime = period - d;
    delayMicroseconds(dtime); // this defines the time between loop iterations
    digitalWrite(led,HIGH);
    delayMicroseconds(d);
    digitalWrite(led,LOW);
  }
  if (i < steplength*3 && i > steplength*2)
  {
    pwm = 4;
    d = period * pwm / 100;
    dtime = period - d;
    delayMicroseconds(dtime); // this defines the time between loop iterations
    digitalWrite(led,HIGH);
    delayMicroseconds(d);
    digitalWrite(led,LOW);
  }
  if (i < steplength*4 && i > steplength*3)
  {
    pwm = 8;
    d = period * pwm / 100;
    dtime = period - d;
    delayMicroseconds(dtime); // this defines the time between loop iterations
    digitalWrite(led,HIGH);
    delayMicroseconds(d);
    digitalWrite(led,LOW);
  }
  if (i < steplength*5 && i > steplength*4)
  {
    pwm = 16;
    d = period * pwm / 100;
    dtime = period - d;
    delayMicroseconds(dtime); // this defines the time between loop iterations
    digitalWrite(led,HIGH);
    delayMicroseconds(d);
    digitalWrite(led,LOW);
  }
  if (i < steplength*6 && i > steplength*5)
  {
    pwm = 32;
    d = period * pwm / 100;
    dtime = period - d;
    delayMicroseconds(dtime); // this defines the time between loop iterations
    digitalWrite(led,HIGH);
    delayMicroseconds(d);
    digitalWrite(led,LOW);
  }
  if (i < steplength*7 && i > steplength*6)
  {
    pwm = 16;
    d = period * pwm / 100;
    dtime = period - d;
    delayMicroseconds(dtime); // this defines the time between loop iterations
    digitalWrite(led,HIGH);
    delayMicroseconds(d);
    digitalWrite(led,LOW);
  }
  if (i < steplength*8 && i > steplength*7)
  {
    pwm = 4;
    d = period * pwm / 100;
    dtime = period - d;
    delayMicroseconds(dtime); // this defines the time between loop iterations
    digitalWrite(led,HIGH);
    delayMicroseconds(d);
    digitalWrite(led,LOW);
  }
  if (i > steplength*8)
  {
    i = 0;
  }
  i = i + 1;
  Serial.print(i);
  Serial.println(' ');
}
