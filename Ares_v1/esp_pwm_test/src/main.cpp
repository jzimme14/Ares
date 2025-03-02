#include <Arduino.h>

// Definiere die PWM-Kanäle
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;
const int pwmChannel3 = 2;

// Definiere die GPIO-Pins für die Phasen
const int phaseA_pin = 13; // GPIO für Phase A
const int phaseB_pin = 14; // GPIO für Phase B
const int phaseC_pin = 18; // GPIO für Phase C

// PWM-Einstellungen
const int pwmFreq = 20000;   // PWM-Frequenz, typischerweise 20kHz für BLDC
const int pwmResolution = 8; // 8-bit Auflösung (Werte von 0 bis 255)

const int period = (1 / pwmFreq) / 3;

// Funktion zur Initialisierung der PWM-Kanäle
void setupPWM()
{
  // Konfiguriere PWM für die Phase A
  ledcSetup(pwmChannel1, pwmFreq, pwmResolution);
  ledcAttachPin(phaseA_pin, pwmChannel1);

  // Konfiguriere PWM für die Phase B
  ledcSetup(pwmChannel2, pwmFreq, pwmResolution);
  ledcAttachPin(phaseB_pin, pwmChannel2);

  // Konfiguriere PWM für die Phase C
  ledcSetup(pwmChannel3, pwmFreq, pwmResolution);
  ledcAttachPin(phaseC_pin, pwmChannel3);
}

// Diese Funktion setzt die PWM-Signale für alle Phasen mit 120° Phasenverschiebung
void setPWMSignal()
{
  int duty = 255 / 3; // Berechne den Duty Cycle (0 bis 255)

  // Setze PWM für Phase A
  ledcWrite(pwmChannel1, duty);

  // Warte für die Phasenverschiebung von 120° (1/3 der Periode)
  delayMicroseconds(period);

  // Setze PWM für Phase B
  ledcWrite(pwmChannel2, duty);

  // Warte für die nächste Phasenverschiebung von 120°
  delayMicroseconds(period / 3);

  // Setze PWM für Phase C
  ledcWrite(pwmChannel3, duty);
}

void setup()
{
  // Initialisiere die PWM-Kanäle
  setupPWM();
}

void loop()
{

  setPWMSignal();
  // // Beispiel: Einfache Rampenfunktion für den Duty Cycle von 0% bis 100%
  // for (float duty = 0.0; duty <= 1.0; duty += 0.01)
  // {
  //   setPWMSignal(duty);
  //   delay(100); // 100ms Verzögerung pro Schritt
  // }

  // // Danach von 100% zurück auf 0%
  // for (float duty = 1.0; duty >= 0.0; duty -= 0.01)
  // {
  //   setPWMSignal(duty);
  //   delay(100); // 100ms Verzögerung pro Schritt
  // }
}
