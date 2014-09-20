
//use pins a1 and a2 for temp sensors.
//6V power supply  2 Amps
//temp sensor data sheet http://ww1.microchip.com/downloads/en/DeviceDoc/21942e.pdf
//mossfet (switch) max voltage is 20V look here for specs : http://www.vishay.com/docs/65154/si4204dy.pdf
//can change temperature set points in test by pressing upload. the set point will change

#define switch1 9
#define switch2 10

//___________________________________________________
int dtime = 3000;  // delay time in millisec (3000 = 3 sec)
int setpt1 = 30; // set pt heater 1
int setpt2 = 30; // set point heater 2
int hyst = 1; // above or below set point before heater is activated
//___________________________________________________
void setup()
{
  Serial.begin(9600);
  pinMode(switch1, OUTPUT);
  pinMode(switch2, OUTPUT);
}
void loop() {
  //get the analog signal
  int sensorValue0 = analogRead(A1);
  int sensorValue1 = analogRead(A2);


  //convert to voltage
  float voltage0 = sensorValue0 * (5.0 /1023);
  float voltage1 = sensorValue1 * (5.0 /1023);


  //convert voltage to temperature in C
  float Const = -50.00 ;
  float temp1 = voltage0 * 100 + Const;
  float temp2 = voltage1 * 100 + Const;

  //sets temp set point in C


  if (temp1 > (setpt1 + hyst))
  {
    digitalWrite(switch1,LOW);
  }
  if (temp1 <(setpt1 - hyst))
  {
    digitalWrite(switch1,HIGH); 
    Serial.println("heating 1");
  }


  if (temp2 > (setpt2 + hyst))
  {
    digitalWrite(switch2,LOW);
  }
  if (temp2 < (setpt2 - hyst))
  {
    digitalWrite(switch2,HIGH); 
    Serial.println("heating 2");
  }



  Serial.print(temp1);
  Serial.print(',');
  Serial.print(temp2);




  Serial.println(' ');

  delay(dtime);
}



