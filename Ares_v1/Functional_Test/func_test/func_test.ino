#include "SAMD_PWM.h"

#define PWM_PIN_1 4  // 3
#define PWM_PIN_2 5
#define PWM_PIN_3 6
#define PWM_PIN_4 9

#define LED_PIN_RED 7
#define LED_PIN_BLUE 8

// LEDs funktionieren
// PWM funktioniert

SAMD_PWM* pwm1;
SAMD_PWM* pwm2;
SAMD_PWM* pwm3;
SAMD_PWM* pwm4;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN_BLUE, OUTPUT);
  pinMode(LED_PIN_RED, OUTPUT);

  digitalWrite(LED_PIN_BLUE, HIGH);
  digitalWrite(LED_PIN_RED, HIGH);
  delay(500);
  digitalWrite(LED_PIN_BLUE, LOW);
  digitalWrite(LED_PIN_RED, LOW);

// Init Sequenz for BLDC Motors
  pwm1 = new SAMD_PWM(PWM_PIN_1, 50, 10);
  pwm2 = new SAMD_PWM(PWM_PIN_2, 50, 10);
  pwm3 = new SAMD_PWM(PWM_PIN_3, 50, 10);
  pwm4 = new SAMD_PWM(PWM_PIN_4, 50, 10);
  delay(2000);

  pwm1->setPWM(PWM_PIN_1, 50, 5);
  pwm2->setPWM(PWM_PIN_2, 50, 5);
  pwm3->setPWM(PWM_PIN_3, 50, 5);
  pwm4->setPWM(PWM_PIN_4, 50, 5);
  delay(2000);
}

void loop() {



  // PWM-Duty-Cycle setzen (Wert zwischen 0 und 2^pwmResolution-1)
  // Init Sequenz zur initialisierung des ESC
  // for (int i = 5; i < 10; i++) {
  //   pwm1->setPWM(PWM_PIN_1, 50, i);
  //   pwm2->setPWM(PWM_PIN_2, 50, i);
  //   pwm3->setPWM(PWM_PIN_3, 50, i);
  //   pwm4->setPWM(PWM_PIN_4, 50, i);
  //   delay(2000);
  // }

  pwm1->setPWM(PWM_PIN_1, 50, 30);
  pwm2->setPWM(PWM_PIN_2, 50, 60);
  pwm3->setPWM(PWM_PIN_3, 50, 70);
  pwm4->setPWM(PWM_PIN_4, 50, 90);


  delay(3000);
}
