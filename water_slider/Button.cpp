#include <Arduino.h>
#include "water_slider.h"
#include "Button.h"

Button::Button(int button_pin, BTN_MODE mode, void* function){
  if(mode == D_READ){
    m_btn_pin = button_pin;
    pinMode(m_btn_pin, INPUT);
  }else{
    attachInterrupt(button_pin, function, CHANGE);
  }
}

int Button::Read(){
  return digitalRead(m_btn_pin);
}
