// PWM-Konfiguration
const int pwmPin = 19; // Pin, an dem das PWM-Signal ausgegeben wird
const int pwmChannel = 0; // PWM-Kanal (0-15 verfügbar)
const int pwmFreq = 50; // PWM-Frequenz in Hz
const int pwmResolution = 16; // Auflösung in Bit (1-16 Bit)

// Geschwindigkeit zwischen 1-2ms einstellbar (3276 - 6553)
// Ganzer PWM Cycle: 20ms

void setup() {
  // PWM-Kanal konfigurieren
  ledcSetup(pwmChannel, pwmFreq, pwmResolution);

  // Kanal mit dem Pin verbinden
  ledcAttachPin(pwmPin, pwmChannel);
}

void loop() {
  // PWM-Duty-Cycle setzen (Wert zwischen 0 und 2^pwmResolution-1)
    ledcWrite(pwmChannel, 4000);
    delay(10000);
}
