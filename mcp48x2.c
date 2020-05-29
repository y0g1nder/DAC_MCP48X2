// /**************************************************************************
// ***************************************************************************/
// *    Project         : Microchip MCP48x2 DAC
// *    Description     : Used to interface MCP48X2 series
// *    Author          : Yoginder Kumar
// *    Workfile        : mcp48x2.c
// *    Revision        : 1.0
// *    Last changed on : Date: 2019-05-23
// /**************************************************************************
// ***************************************************************************/

#include "mcp48x2.h"

unsigned int res_config;



void MCP48X2_init()
{
  mcp48x2_cs_Dir   = SET_OUTPUT;
  mcp48x2_sck_Dir  = SET_OUTPUT;
  mcp48x2_sdo_Dir  = SET_OUTPUT;
  mcp48x2_ldac_Dir = SET_OUTPUT;
}


void MCP48X2_CONFIG(unsigned int channel, unsigned int gain, unsigned int output_enable)
{
   res_config = channel|gain|output_enable;       //Settings to control register of mcp49x2mcp48x2
}
unsigned int Vol2Bitcon(float dac_out)       // This function is for the conversion of voltage into hex code to write to the control register
{
  unsigned int DATA_BITS;
  #if (MCP48X2 == MCP4802)
   {   
     if(!(res_config & 0x2000))
     {
      DATA_BITS = dac_out/0.016;
      DATA_BITS <<= 4;
      }
     else
     {
      DATA_BITS = dac_out/0.008;
      DATA_BITS <<= 4;
      }
    }
  #elif  (MCP48X2 == MCP4812)
  {
   if(!(res_config & 0x2000))
   {
    DATA_BITS = dac_out/0.004;
    DATA_BITS <<= 2;
    }
   else
   {
    DATA_BITS = dac_out/0.002;
    DATA_BITS <<= 2;
    }
   }

  #elif (MCP48X2 == MCP4822)
  {
   if(!(res_config & 0x2000))
   {
    DATA_BITS = dac_out/0.001;
    }
   else
   {
    DATA_BITS = dac_out/0.0005;
    }
   }
  #endif
  return DATA_BITS; 
}


void MCP48X2_write(float dac_out)        // This function is capable to write the data to dac with any 4 i/o pins
{
  unsigned char bit_no;
  unsigned int res_value, data_value, bit_shift = 0x8000;
  data_value = Vol2Bitcon(dac_out);
  res_value = res_config|data_value;

    mcp48x2_ldac = LOW;
    mcp48x2_cs = HIGH;
    delay_ms(1);
    mcp48x2_cs = LOW;
    delay_ms(1);

    for(bit_no = 0; bit_no<=15; bit_no++)
    {
      mcp48x2_sck = LOW;

      if ((res_value & bit_shift)==0)
      mcp48x2_sdo = LOW;
      else
      mcp48x2_sdo = HIGH;

      delay_us(100);
      mcp48x2_sck = HIGH;
      delay_us(100);
      bit_shift >>= 1;
    }

    mcp48x2_cs = HIGH;
    delay_ms(1);
}