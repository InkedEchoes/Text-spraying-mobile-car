/*
 云台控制程序
 */

#include "stage.h"
#include <Arduino.h>

// 云台初始化
// X轴0点靠近电机,Z轴0点靠近电机
void stageInit() {
  pinMode(StageX_go, OUTPUT);
  pinMode(StageX_back, OUTPUT);
  pinMode(StageZ_go, OUTPUT);
  pinMode(StageZ_back, OUTPUT);
  //位置还原
  //stageLeftX(20);
  //stageUpZ(20);
}

// 云台X方向左移delta
void stageLeftX(int delta) {
  analogWrite(StageX_go, 0);
  analogWrite(StageX_back, 255);
  delay(StageXTick * delta);
  analogWrite(StageX_go, 0);
  analogWrite(StageX_back, 0);
}

// 云台X方向右移delta
void stageRightX(int delta) {
  analogWrite(StageX_go, 255);
  analogWrite(StageX_back, 0);
  delay(StageXTick * delta);
  analogWrite(StageX_go, 0);
  analogWrite(StageX_back, 0);
}

// 云台Z方向上移delta
void stageUpZ(int delta) {
  analogWrite(StageZ_go, 255);
  analogWrite(StageZ_back, 0);
  delay(StageZTick * delta);
  analogWrite(StageZ_go, 0);
  analogWrite(StageZ_back, 0);
}

// 云台Z方向下移delta
void stageDownZ(int delta) {
  analogWrite(StageZ_go, 0);
  analogWrite(StageZ_back, 255);
  delay(StageZTick * delta);
  analogWrite(StageZ_go, 0);
  analogWrite(StageZ_back, 0);
}

// 根据输入字符控制云台
// I Z方向上移1个单位
// M Z方向下移1个单位
// J X方向左移1个单位
// K X方向右移1个单位
void stageControl(char c) {
  Serial.print("Stage Control : ");
  Serial.println(c);
  if (c == 'I') {
    stageUpZ(1);
  } else if (c == 'M') {
    stageDownZ(1);
  } else if (c == 'J') {
    stageLeftX(1);
  } else if (c == 'K') {
    stageRightX(1);
  }
}
