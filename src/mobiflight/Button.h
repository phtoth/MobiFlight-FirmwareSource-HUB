//
// Button.h
//
// (C) MobiFlight Project 2022
//

#pragma once

#include <stdint.h>

namespace Button
{
    void Add(uint8_t pin, char const *name = "Button");
    void Clear();
    void read(int *BTN_List);
    void OnTrigger();
}

// Button.h
