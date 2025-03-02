#include <Arduino.h>

// PWM-Konfiguration
const int pwmPin = 19;        // Pin, an dem das PWM-Signal ausgegeben wird
const int pwmChannel = 0;     // PWM-Kanal (0-15 verfügbar)
const int pwmFreq = 50;       // PWM-Frequenz in Hz
const int pwmResolution = 16; // Auflösung in Bit (1-16 Bit)

// Geschwindigkeit zwischen 1-2ms einstellbar (3276 - 6553)
// Ganzer PWM Cycle: 20ms

const int analogPin = 34;

void setup()
{
  Serial.begin(9600);

  // PWM-Kanal konfigurieren
  ledcSetup(pwmChannel, pwmFreq, pwmResolution);

  // Kanal mit dem Pin verbinden
  ledcAttachPin(pwmPin, pwmChannel);
}

void loop()
{
  // PWM-Duty-Cycle setzen (Wert zwischen 0 und 2^pwmResolution-1)
  // Init Sequenz zur initialisierung des ESC
  ledcWrite(pwmChannel, 6553);
  delay(100);
  ledcWrite(pwmChannel, 3276);
  delay(1000);

  while (1)
  {
    ledcWrite(pwmChannel, 3500);
    delay(3000);
    ledcWrite(pwmChannel, 4400);
    delay(3000);
    ledcWrite(pwmChannel, 5500);
    delay(3000);
    ledcWrite(pwmChannel, 6000);
    delay(3000);
  }
}
