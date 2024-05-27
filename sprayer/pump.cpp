/*
 水泵控制程序
 */

#include "pump.h"
#include <Arduino.h>

// 水泵初始化
void pumpInit() {
  pinMode(PumpPin, OUTPUT);
  pumpDown(1);
}

// 水泵开n个Tick
void pumpUp(int n) {
  //LOW代表水泵开，HIGH代表水泵关
  digitalWrite(PumpPin, LOW);
  delay(PumpTick * n);
}

// 水泵关n个Tick
void pumpDown(int n) {
  //LOW代表水泵开，HIGH代表水泵关
  digitalWrite(PumpPin, HIGH);
  delay(PumpTick * n);
}

// 根据输入字符控制水泵
// A 开1个Tick
// B 开10个Tick
// C 开100个Tick
// Z 关1个Tick
void pumpControl(char c) {
  Serial.print("Pump Control : ");
  Serial.println(c);
  if (c == 'A') {
    pumpUp(1);
  } else if (c == 'B') {
    pumpUp(10);
  } else if (c == 'C') {
    pumpUp(100);
  } else if (c == 'Z') {
    pumpDown(1);
  }
}
