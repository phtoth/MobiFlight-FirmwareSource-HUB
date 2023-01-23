#include <SPI.h>
#include <mcp2515.h>

MCP2515 mcp2515(10);

struct can_frame canMsg;
int msgData0 = 0;


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
      
      //Serial.println(canMsg.data[0]);
      //Serial.println(canMsg.data[2]);  
      
      
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
          
          //Serial.println(ANL_List[canMsg.data[1]]);
          break;
    }

   
 
    }
  }
  
  
}
