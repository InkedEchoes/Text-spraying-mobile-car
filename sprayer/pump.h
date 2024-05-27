#ifndef _PUMP_H_
#define _PUMP_H_

#include <Arduino.h>

// 水泵引脚
const int PumpPin = 2;

// 水泵时间Tick
const int PumpTick = 10;

// 水泵初始化
void pumpInit();

// 水泵开n个Tick
void pumpUp(int n);

// 水泵关n个Tick
void pumpDown(int n);

// 根据输入字符控制水泵
void pumpControl(char c);

#endif
