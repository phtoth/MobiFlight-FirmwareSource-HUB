//
// MFSegments.cpp
//
// (C) MobiFlight Project 2022
//

#include "MFSegments.h"
#include "mobiflight.h"


MFSegments::MFSegments()
{
    _moduleCount = 0;
}

void MFSegments::display(int module, int SubModule, char *string, byte points, byte mask, bool convertPoints)
{

    /*
    if (module == 1)
    {
        UpdateDisplayData(_pin_A, *string);
    }
    else if (module == 2)
    {
        UpdateDisplayData(_pin_B, *string);
    }
*/
    
    if (_moduleCount == 0)
        return;
    byte digit = 8;
    byte pos   = 0;
    int total = 0;

    /*
    // Envio do Valor do LCD
    for (uint8_t i = 0; i < 8; i++) 
    {
        digit--;
        if (((1 << digit) & mask) == 0)
            continue;
            
        int value = sizeof(*string);
        
        UpdateDisplayData(module, SubModule, value);
        //_ledControl.setChar(module, digit, string[pos], ((1 << digit) & points));
        pos++;
    }
    */
        //ajuste para o heading, com 3 digitos

        float TempFloat = atof(string);
        int TempInt = round(TempFloat);
        UpdateDisplayData(module, SubModule, TempInt);
        
        
        //int CharSize = sizeof(string);
       

        
        /*
        for(int p = 0; p <= CharSize; p++)
        {
          
       


          // nao rolou com atoi
            UpdateDisplayData(module, SubModule, );
        }
        
        //(int(string[p])) 
    
    */
}


void MFSegments::setBrightness(byte module, byte value)
{
    if (_moduleCount == 0)
        return;
    if (module < _moduleCount) {
        if (value) {
            //_ledControl.setIntensity(module, value - 1);
            //_ledControl.shutdown(module, false);
        } else {
            //_ledControl.shutdown(module, true);
        }
    }
}
//void MFSegments::attach(int dataPin, int csPin, int clkPin, byte moduleCount, byte brightness)
void MFSegments::attach(int csPin, byte moduleCount)
{
    //_ledControl.begin(dataPin, clkPin, csPin, moduleCount);
    _moduleCount = moduleCount;
    
    if(_moduleCount == 1)
    {
        _pin_A = csPin;
    }
    else if(_moduleCount == 2)
    {
        _pin_B = csPin;
    }

    //for (uint8_t i = 0; i < _moduleCount; ++i) {
        //setBrightness(i, brightness);
        //_ledControl.shutdown(i, false);
        //_ledControl.clearDisplay(i);
    //}
}

void MFSegments::detach()
{
    _moduleCount = 0;
}

void MFSegments::powerSavingMode(bool state)
{
    for (byte i = 0; i != _moduleCount; ++i) {
        //_ledControl.shutdown(i, state);
    }
}

void MFSegments::test()
{
    if (_moduleCount == 0)
        return;
    byte _delay = 10;
    byte module = 0;
    byte digit  = 0;

    for (digit = 0; digit < 8; digit++) {
        for (module = 0; module != _moduleCount; ++module) {
            //_ledControl.setDigit(module, digit, 8, 1);
        }
        delay(_delay);
    }

    for (digit = 0; digit < 8; digit++) {
        for (module = 0; module != _moduleCount; ++module) {
            //_ledControl.setChar(module, 7 - digit, '-', false);
        }
        delay(_delay);
    }

    for (digit = 0; digit < 8; digit++) {
        for (module = 0; module != _moduleCount; ++module) {
            //_ledControl.setChar(module, 7 - digit, ' ', false);
        }
        delay(_delay);
    }
}

// MFSegments.cpp
