/*
  Alcohol Detection Based Engine Locking System
  Board: ESP32
*/

#define SENSOR_PIN 34     // Alcohol sensor output (ADC)
#define RELAY_PIN 23      // Relay control pin
#define BUZZER_PIN 25     // Buzzer control pin

#define THRESHOLD 2000    // Adjust after testing (0 - 4095)

void setup() 
{
    Serial.begin(115200);

    pinMode(RELAY_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    digitalWrite(RELAY_PIN, HIGH);   // Relay ON (Engine allowed)
    digitalWrite(BUZZER_PIN, LOW);   // Buzzer OFF
}

void loop() 
{
    int sensorValue = analogRead(SENSOR_PIN);

    Serial.print("Alcohol Sensor Value: ");
    Serial.println(sensorValue);

    if (sensorValue > THRESHOLD)
    {
        // Alcohol detected
        digitalWrite(RELAY_PIN, LOW);    // Turn OFF relay (Engine locked)
        digitalWrite(BUZZER_PIN, HIGH);  // Buzzer ON
    }
    else
    {
        // No alcohol detected
        digitalWrite(RELAY_PIN, HIGH);   // Relay ON (Engine allowed)
        digitalWrite(BUZZER_PIN, LOW);   // Buzzer OFF
    }

    delay(500);
}
