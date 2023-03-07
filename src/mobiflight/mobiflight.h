//
// mobiflight.h
//
// (C) MobiFlight Project 2022
//

#pragma once

#include <Arduino.h>
#include "MFBoards.h"
#include "config.h"
#include "allocateMem.h"
#include "commandmessenger.h"

void UpdateLedList(int _pin, int _code);
void UpdateDisplayData(int module, int SubModule, int value);


// mobiflight.h