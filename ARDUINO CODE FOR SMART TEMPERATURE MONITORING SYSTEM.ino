// SMART TEMPERATURE MONITOR

const int sensorPin = A0; // defining input analog pin
const int led_Pin = 3;    // defining output digital pin

void setup() {
  // begin serial monitor
  Serial.begin(9600);
  // declare output pin
  pinMode(led_Pin, OUTPUT);
}

void loop() {
  // read ADC value from TMP36 
  int sensorValue = analogRead(sensorPin);

  // Convert ADC value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // TMP36 temperature calculation
  float temperatureC = (voltage - 0.5) * 100.0;
  
  // convertion of temperature
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  
  // print the temperature values in serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" C  |  ");
  Serial.print(temperatureF);
  Serial.println(" F");
  
  // set threshold value as 50.0, if temperature crosses threshold value led glows up and print warning in serial monior
  if (temperatureC > 50.0) {
     digitalWrite(led_Pin, HIGH);
     Serial.println("High Temperature!!");
  }
  else {
      digitalWrite(led_Pin, LOW);
  } 
  
  // 1 sec delay for accurate measurement
  delay(1000);
}
