
// test flashing an LED

#define led 13 // #define constant_name value // sets a constant that is compiled to the value later

//___________________________________________________
// int defines a variable as an integer
int dtime = 1000;  // delay time in millisec (3000 = 3 sec)
int min_time = 10;
int d = dtime;
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
  if (d < min_time)
  {
    d = dtime;
  }
  Serial.println("flash"); //println('string'), Prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
  Serial.print(d);
  digitalWrite(led,HIGH);
  delay(d); // this defines the time between loop iterations
  digitalWrite(led,LOW);
  delay(d);
  d = d/1.1;
}
