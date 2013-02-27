void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int sensorValue = analogRead(A0);
  float voltage = 5.0 * sensorValue / 1023.0;
  float tempC = voltage * 100 - 50;
  float tempF = tempC * 9/5 + 32;
  
  Serial.print("Reading: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print(", Temp C: ");
  Serial.print(tempC);
  Serial.print(", Temp F: ");
  Serial.println(tempF);
  
}
