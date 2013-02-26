/*
  ReadAnalogVoltage
 Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
 Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */
const int numberOfSensors = 3;
//int sensorValue [numberOfSensors] = {0,0,0};
float voltage[numberOfSensors] = {0,0,0};
float actualValue[numberOfSensors] = {0,0,0};
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

  actualValue[0] = (2.31 - voltage[0]) * 10;
  actualValue[2] = (100.0 * voltage[1] - 50) * 9 / 5 + 32;
  actualValue[1] *= 2.0;

    for(int i = 0; i < numberOfSensors; i++)
  {
    Serial.print(actualValue[i]);
    Serial.print(" ");
  }
  
  Serial.println();
}

