#include <Arduino.h>
#include <Arduino_LSM6DS3.h>

typedef struct
{
  // Voltages of specific Lipo Cells
  float V1s;
  float V2s;
  float V3s;

} FlightDiary;

/* Geschwindigkeit zwischen 1-2ms einstellbar (3276 - 6553)
 Ganzer PWM Cycle: 20ms
*/

float x, y, z;
float xA, yA, zA;

// const int analogPin = 34;

void setup()
{
  Serial.begin(9600);

  // pinMode(17, OUTPUT);
  IMU.begin();
}

void loop()
{
  // Testing

  if (IMU.gyroscopeAvailable())
  {

    IMU.readGyroscope(x, y, z);
    IMU.readAcceleration(xA, yA, zA);
  }

  Serial.print(x);

  Serial.print('\t');

  Serial.print(y);

  Serial.print('\t');

  Serial.println(z);

  Serial.print(xA);

  Serial.print('\t');

  Serial.print(yA);

  Serial.print('\t');

  Serial.println(zA);
  Serial.print('\n');

  delay(2000);

  for (int i = 0; i < 1024; i++)
  {
    analogWrite(17, i);
    delay(100);
  }

  // Testing end

  // getBatVoltages();

  // check if Battery Voltages are valid/high enough each

  // calculate 3 axis position (sensor fusion (kalman/complementary filter))

  // control propeller speeds according to sensor readings and readings from the controller

  // optional: get gps position

  // send telemetry data
}