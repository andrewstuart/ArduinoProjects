/*
Sensors Implementation

This is code for testing sensors using the arduino.  Also used for honing my skills toward eventual home automation project.
 */

const int numberOfSensors = 3;
const String sensorIdentities[numberOfSensors] = {"Sound", "Light", "Temperature"};
float voltage[numberOfSensors] = {0,0,0};
float actualValue[numberOfSensors] = {0,0,0};

int delaytime = 500, currentMin = 0;
short int count = 0;
unsigned long currentMil = 0;
float currentSec = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue[numberOfSensors] = {analogRead(A0), analogRead(A1), analogRead(A2)};
  for(int i = 0; i < numberOfSensors; i++)
  {
    voltage[i] = sensorValue[i] * 5.0 / 1023.0;
  }

  actualValue[0] += abs((2.31 - voltage[0]) * 10);
  actualValue[1] += voltage[1] * 2.0;
  actualValue[2] += (voltage[2] * 100 - 50) * 9.0 / 5.0 + 32.0;
  
  count++;
  
  currentMil = millis();
  
  
  if(currentMil % delaytime == 0)
  {
    
    if(currentSec > 60)
    {
      Serial.print(currentMil / 1000 / 60);
      Serial.print(" Minutes ");
    }
    
    Serial.print(currentMil % 60 );
    Serial.print(" Seconds: ");
    Serial.print();
    
    for(int i = 0; i < numberOfSensors; i++)
    {
      Serial.print(sensorIdentities[i]);
      Serial.print(" ");
      Serial.print(actualValue[i] / count);
      Serial.print(" ");
      actualValue[i] = 0;
    }
    
    Serial.println();
    
    count = 0;
  }
}

