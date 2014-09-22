//use pins 9 and 10 for connections to the mossfet
//use pins a- and a1 for temp sensors.
// 6V power supply  2 Amps

int switch1 = 9;
int switch2 = 10;
int dtime = 3000;
int setpt1 = 40;
  int setpt2 = 20;

void setup()
{
  Serial.begin(9600);
}
void loop() {
  //get the analog signal
  int sensorValue0 = analogRead(A1);
  int sensorValue1 = analogRead(A2);
  
  
  //convert to voltage
  float voltage0 = sensorValue0 * (5.0 /1023);
  float voltage1 = sensorValue1 * (5.0 /1023);
  
  
  //convert voltage to temperature in C
  float Const = -51.56 ;
  float temp1 = voltage0 * 103.125 + Const;
  float temp2 = voltage1 * 103.125 + Const;
  
  //sets temp set point in C
 
  
  if (temp1 > (setpt1+3))
    {
      digitalWrite(switch1,LOW);
    }
  if (temp1 <(setpt1 -3))
    {
     digitalWrite(switch1,HIGH); 
    }
    

  if (temp2 > (setpt2+3))
    {
         digitalWrite(switch2,LOW);
    }
  if (temp2 < (setpt2-3))
    {
      digitalWrite(switch2,HIGH); 
    }
    
   
  
  Serial.print(temp1);
  Serial.print(',');
    Serial.print(temp2);
  
  
    
  
  Serial.println(' ');
  
  delay(dtime);
}


