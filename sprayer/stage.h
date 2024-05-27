#ifndef _STAGE_H_
#define _STAGE_H_

#include <Arduino.h>

// 云台X方向引脚
const int StageX_go = 3;  //IN1,IN2
const int StageX_back = 5;

// 云台Z方向引脚
const int StageZ_go = 9;  //IN3,IN4
const int StageZ_back = 10;

// 云台X方向时间Tick
const int StageXTick = 500;

// 云台Z方向时间Tick
const int StageZTick = 500;

// 云台初始化
void stageInit();

// 云台X方向左移delta
void stageLeftX(int delta);

// 云台X方向右移delta
void stageRightX(int delta);

// 云台Z方向上移delta
void stageUpZ(int delta);

// 云台Z方向下移delta
void stageDownZ(int delta);

// 根据输入字符控制云台
void stageControl(char c);

#endif

