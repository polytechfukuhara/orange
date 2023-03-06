#include <Arduino.h>
#include "LCD.h"
#include <Wire.h>

// 初期化処理
void Lcd::init(){
  Wire.begin();
  init_LCD();
}

// 文字データ送信処理
void Lcd::writeData(byte t_data)
{
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x40);
  Wire.write(t_data);
  Wire.endTransmission();
  delay(1);
}

// コマンド送信処理
void Lcd::writeCommand(byte t_command)
{
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x00);
  Wire.write(t_command);
  Wire.endTransmission();
  delay(10);
}

// LCDの初期化処理
void Lcd::init_LCD() {
  delay(100);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x39);
  delay(20);
  writeCommand(0x14);
  delay(20);
  writeCommand(0x73);
  delay(20);
  writeCommand(0x52);
  delay(20);
  writeCommand(0x6C);
  delay(20);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x01);
  delay(20);
  writeCommand(0x0F);
  delay(20);
}

/*整数型変数などの数値を文字としてLCDに表示する関数*/
void Lcd::printData(int data){
  String temp = (String)data;
  int i  = 0;
  int len = temp.length();

  for(i = 0; i < len; i++){
    writeData(temp.charAt(i)); //CharAt()...引数で指定した位置の文字を返す
    delay(1);
  }
}

/*LCDのカーソルを自由に移動させる関数*/
void Lcd::cursorMove(int place){     //返却値なし　引数　整数型(カーソルを移動させたいアドレス)
  writeCommand(place + 0x80);   //インストラクションコード 0x80 カーソル移動
                                //それに移動させたいアドレスを足し合わせることで　そのアドレスにカーソルを移動させる
                                // writeCommand(place + 0x80);　が  プログラム中に出てきてもインストラクションコードを分からないと読めない
                                // cursorMoveなら名前から意味が想像しやすく　可読性　を上げることができる
}

/*引数で渡した文字列を表示させる。開始位置は1行目の先頭から。*/
void Lcd::lcd_print(String str){
  cursorMove(0x00);
  writeCommand(0x01);
  printString(str);
}

void Lcd::printString(String str){
  int i  = 0;
  int len = str.length();

  for(i = 0; i < len; i++){
    writeData(str.charAt(i)); //CharAt()...引数で指定した位置の文字を返す
    delay(1);
  }
}
