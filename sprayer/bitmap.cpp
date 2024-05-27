/*
 点阵图形绘制程序
 */

#include "bitmap.h"
#include "pump.h"
#include "stage.h"
#include <Arduino.h>

// 画一个点
void paintPoint() {
  pumpUp(3);
  pumpDown(1);
}

// 取字节b中的第n位
int getBit(unsigned char b, int n) {
  return ((b >> n) & 0x01);
}

// 画一个点阵图形,宽n * 高m
// 点i行(从0开始),j列(从0开始) 对应image[i*n/8+j/8],bit[7-j%8]
void paintImage(unsigned char image[], int n, int m, char c) {
  Serial.print("Paint Image begin (");
  Serial.print(n);
  Serial.print("*");
  Serial.print(m);
  Serial.print(") : ");
  Serial.println(c);
  // 返回原点
  stageUpZ(m);
  stageLeftX(n);
  for (int i = 0; i < m; i++) {
    if (i % 2 == 0) {
      // 偶数行从左到右
      for (int j = 0; j < n; j++) {
        int x = getBit(image[i * n / 8 + j / 8], 7 - j % 8);
        if (x == 1) {
          paintPoint();
          Serial.print('1');
        } else {
          Serial.print('0');
        }
        stageRightX(1);
      }
      stageDownZ(1);
      Serial.println();
      stageLeftX(1);
    } else {
      // 奇数行从右到左
      for (int j = n - 1; j >= 0; j--) {
        int x = getBit(image[i * n / 8 + j / 8], 7 - j % 8);
        if (x == 1) {
          paintPoint();
          Serial.print('1');
        } else {
          Serial.print('0');
        }
        stageLeftX(1);
      }
      stageDownZ(1);
      Serial.println();
      stageRightX(1);
    }
  }
  Serial.print("Paint Image end");
}
