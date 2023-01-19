//
// MFButton.cpp
//
// (C) MobiFlight Project 2022
//

// Modified by Pedro Henrique Toth - 2022

#include "MFButton.h"

buttonEvent MFButton::_handler = NULL;

MFButton::MFButton(uint8_t pin, const char *name)
{
    _pin   = pin;
    _name  = name;
    //pinMode(_pin, INPUT_PULLUP);    // set pin to input
    //_state = digitalRead(_pin);     // initialize on actual status
    _state = -1;
}

void MFButton::update(int *BTN_List)
{
    //uint8_t newState = (uint8_t)digitalRead(_pin);
    //uint8_t newState = (uint8_t)LOW;
    //uint8_t newState = (uint8_t)HUB_Mapping._teste_state;
    uint8_t newState = (uint8_t)BTN_List[_pin];


    //Serial.println(BTN_List[0]); 

    if (newState != _state)
     {
        _state = newState;
        trigger(_state);
        //Serial.println("mudou");
     }
}

void MFButton::trigger(uint8_t state)
{
    (state == LOW) ? triggerOnPress() : triggerOnRelease();
}

void MFButton::triggerOnPress()
{
    if (_handler && _state == LOW) 
    {
        (*_handler)(btnOnPress, _pin, _name);
    }
}

void MFButton::triggerOnRelease()
{
    if (_handler && _state == HIGH)
    {
        (*_handler)(btnOnRelease, _pin, _name);
    }
}

void MFButton::attachHandler(buttonEvent newHandler)
{
    _handler = newHandler;
}

// MFButton.cpp
