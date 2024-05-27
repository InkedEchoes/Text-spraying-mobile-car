/*
 喷枪控制程序
 */
#include "bitmap.h"
#include "pump.h"
#include "stage.h"
#include "led.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

// global时间Tick
const int globalTick = 2;

// 串口波特率
const int baudrate = 9600;

// 软件串口Rx引脚
const int ssRxPin = 12;

// 软件串口Tx引脚
const int ssTxPin = 11;

// 软件串口
SoftwareSerial softSerial = SoftwareSerial(ssRxPin, ssTxPin);

// 硬件串口输入
String sData = "";

// 软件串口输入
String ssData = "";

void setup() {
  //初始化串口通信:
  Serial.begin(baudrate);
  //初始化软串口通信；
  softSerial.begin(baudrate);
  //监听软串口通信
  softSerial.listen();
  stageInit();
  pumpInit();
  ledInit();
  Serial.println('App setup');
  ledBlink(3);
}

void loop() {
  char val;
  while (Serial.available() > 0) {
    val = char(Serial.read());
    if ((val != '\r') && (val != '\n')) {
      sData += val;
    } else {
      if (sData.length() > 0) {
        Serial.println("S rcv : " + sData);
        doCmd(sData);
        serial.println("done");
        sData = "";
      }
    }
  }
  while (softSerial.available() > 0) {
    val = char(softSerial.read());
    if ((val != '\r') && (val != '\n')) {
      ssData += val;
    } else {
      if (ssData.length() > 0) {
        Serial.println("SS rcv : " + ssData);
        doCmd(ssData);
        softSerial.println("done");
        ssData = "";
      }
    }
  }
  delay(globalTick);
}

// 根据输入字符串控制系统各部件
void doCmd(String s) {
  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    if (c == 'I' || c == 'M' || c == 'J' || c == 'K') {
      stageControl(c);
    } else if (c == 'A' || c == 'B' || c == 'C' || c == 'Z') {
      pumpControl(c);
    } else if (c == 'P') {
      i++;
      if (i < s.length()) {
        char ch = s[i];
        if (ch >= 'A' && ch <= 'Z') {
          paintImage(images[ch - 65], 16, 16, ch);
        }
      }
    } else if (c == 'X') {
      ledBlink(3);
    }
  }
}
