/*
 * This script reads input from piezo panels, filters to the predefined range, counts the number of inputs
 * Please make sure the analog input signal is adjusted/mapped to the range 0-5V
 * Version 1.0.0
 * 
 * By:
 *    Jash Bharat Mota
 *     jash@lyflime.com
 *    http://www.jashmota.esy.es
 */

// these constants won't change:
const int knockSensor = A1; // the piezo is connected to analog pin 0


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int count = 0;
void setup() {
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);

  //Range filteration and count
  lowerRange = 500;
  higherRange = 1023;
  if(sensorReading > lowerRange && sensorReading <= higherRange)
  {
    count++;
  }
  delay(500);  // delay to avoid overloading the serial port buffer
  Serial.print("Voltage: ");
  Serial.println(sensorReading);
}

