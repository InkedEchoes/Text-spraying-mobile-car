#ifndef _LED_H_
#define _LED_H_

#include <Arduino.h>

// LED引脚
const int LedPin = 13;

// LED时间Tick
const int LedTick = 100;

// LED初始化
void ledInit();

// LED开
void ledOn();

// LED关
void ledOff();

// LED闪烁n个Tick
void ledBlink(int n);

#endif
