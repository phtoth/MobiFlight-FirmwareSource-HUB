void Setup__CAN_Bus()
{
  SPI.begin();
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ);
  mcp2515.setNormalMode();
}

void Check_CAN_Bus(int *BTN_List, int *ANL_List)
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
  { 
    if (canMsg.can_id == 0x036)
    {    
      switch(canMsg.data[0]) 
      {
          case 1:
            if(canMsg.data[2] == 1)
            {
              BTN_List[canMsg.data[1]] = HIGH;
            }
            else
            {
              BTN_List[canMsg.data[1]] = LOW;
            }
            break;
          case 2:
            if (canMsg.data[2] == 0)
            {
              ANL_List[canMsg.data[1]] = canMsg.data[3];
            }
            else if (canMsg.data[2] == 1)
            {
              ANL_List[canMsg.data[1]] = canMsg.data[3] + 254;
            }
            else if (canMsg.data[2] == 2)
            {
              ANL_List[canMsg.data[1]] = canMsg.data[3] + 508;
            }
            else if (canMsg.data[2] == 3)
            {
              ANL_List[canMsg.data[1]] = canMsg.data[3] + 762;
            }
            else if (canMsg.data[2] == 4)
            {
              ANL_List[canMsg.data[1]] = canMsg.data[3] + 1016;
            }
            break;
      }
    }
  }
}

// ARRUMAR PARA DECRESCER O VALOR DE LED LIST CONTROL
//Verificar modelo de envio



void SendLedData(int _pin, int _code)
{
        canMsg.can_id  = 0x037;
        canMsg.can_dlc = 3;
        canMsg.data[0] = 1; // Tipo Led
        canMsg.data[1] = _pin; // Pino do Led


        if(_code == 0)
        {
          canMsg.data[2] = 0;
        }
        else
        {
          canMsg.data[2] = 1;
        }

         mcp2515.sendMessage(&canMsg);
        
        delay(2);
        
  /*
  if(LedListControl >= 1)
  {
    for(int p=1; p <= LedListControl; p++)
    {
        canMsg.can_id  = 0x037;
        canMsg.can_dlc = 3;
        canMsg.data[0] = 1; // Tipo Led
        //canMsg.data[1] = LedListPinout[p]; // código do led
        canMsg.data[1] = _pin;
        
        if (_code == 255)
        {
          canMsg.data[2] = 1;
        }
        
        mcp2515.sendMessage(&canMsg);

        //LedListPinout[p] = -1;
        //LedListState[p] = -1;
        
        delay(5);
    }
    //LedListControl = 0;
  }
  */
}
