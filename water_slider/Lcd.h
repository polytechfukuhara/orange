/* インクルードガード */
#pragma once

#define LCD_ADRS 0x3E

class Lcd     // classの定義
{
  private :               // privateはクラス内からしかアクセスできない
    void init_LCD();
    void printString(String str);
    
  public :                // publicはどこからでもアクセス可能
    void init();
    void writeData(byte t_data);
    void writeCommand(byte t_command);   
    void printData(int data);
    void cursorMove(int place);
    void lcd_print(String str);
};
