char temp = 0;
String str = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.write("We have liftoff!");
}

void loop() {
  // put your main code here, to run repeatedly: 
  temp = Serial.read();
  
  if(temp != -1)
  {
    str.concat(temp);
    Serial.println(str);
  }
}
