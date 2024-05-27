/*
 LED控制程序
 */

#include "led.h"
#include <Arduino.h>

// LED初始化
void ledInit() {
  pinMode(LedPin, OUTPUT);
}

// LED开
void ledOn() {
  digitalWrite(LedPin, HIGH);
}

// LED关
void ledOff() {
  digitalWrite(LedPin, LOW);
}

// LED闪烁n个Tick
void ledBlink(int n) {
  Serial.print("LED Blink : ");
  Serial.println(n);
  for (int i = 0; i < n; i++) {
    digitalWrite(LedPin, HIGH);
    delay(LedTick);
    digitalWrite(LedPin, LOW);
    delay(LedTick);
  }
}
