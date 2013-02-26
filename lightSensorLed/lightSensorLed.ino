/*
  ReadAnalogVoltage
 Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
 Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */
int led = 13, pinIn = 2;
long shadowTime = 0;
long timestamp = 0, debounceTimestamp = 0, debounceDelay = 500;
boolean shadowed = 0, buttonPressed = 0, toggle = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, 1);
  pinMode(pinIn, 0);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage = 5.0 * sensorValue / 1023;
  
  if(!toggle)
  {
    Serial.print(shadowTime);
    Serial.print(" ");
    Serial.println(voltage);
  }
  else
  {
    Serial.print(shadowTime / 1000.0);
    Serial.print(" ");
    Serial.println(voltage);
  }
  
  if(digitalRead(pinIn) && millis() - debounceTimestamp > debounceDelay)
  {
    debounceTimestamp = millis();
    toggle = !toggle;
  }
  
  if(voltage < 4)
  {
    digitalWrite(led, 1);
    
    if(!shadowed)
    {
      shadowed = 1;
      timestamp = millis();
    }
  }
  else
  {
    digitalWrite(led, 0);
    
    if(shadowed)
    {
      shadowed = 0;
      shadowTime += millis() - timestamp;
    }
  }
}

