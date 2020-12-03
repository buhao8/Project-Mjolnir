void setup() {
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);
  if (sensorValue >= 400){
    digitalWrite(10, HIGH);
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(10, LOW);  
    digitalWrite(5, HIGH); 
  }
}
