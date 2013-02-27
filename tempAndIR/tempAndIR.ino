float voltage[2] = {0,0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int sensorValue[2] = {analogRead(A0), analogRead(A1)};
  for(int i = 0; i < 2; i++)
  {
    voltage[i] = 5.0 * sensorValue[i] / 1023.0;
  }
  
  float tempC = voltage[0] * 100 - 50;
  float tempF = tempC * 9/5 + 32;
  
  for(int i = 0; i < 2; i++)
  {
    Serial.print("Reading: ");
    Serial.print(sensorValue[i]);
    Serial.print(", Voltage: ");
    Serial.print(voltage[i]);
  }
  
  Serial.println();
//  Serial.print(", Temp C: ");
//  Serial.print(tempC);
//  Serial.print(", Temp F: ");
//  Serial.println(tempF);
  
}
