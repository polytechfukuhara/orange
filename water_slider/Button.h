/* インクルードガード */
#pragma once

typedef enum{
  D_READ,
  INTERRUPT
}BTN_MODE;

class Button     // classの定義
{
  private :                   // privateはクラス内からしかアクセスできない
    int m_btn_pin;
    
  public :                    // publicはどこからでもアクセス可能
    Button(int button_pin, BTN_MODE mode, void* function);   // コンストラクター
    int Read();               // 押されたかReadする関数
};
