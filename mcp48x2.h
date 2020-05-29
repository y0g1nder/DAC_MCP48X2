// /**************************************************************************
// ***************************************************************************/
// *    Project         : Microchip MCP48x2 DAC
// *    Description     : Used to interface MCP48X2 series
// *    Author          : Yoginder Kumar
// *    Workfile        : mcp48x2.h
// *    Revision        : 1.0
// *    Last changed on : Date: 2019-05-23
// /**************************************************************************
// ***************************************************************************/


#define MCP4802  0
#define MCP4812  1
#define MCP4822  2

#define SET_INPUT   1
#define SET_OUTPUT  0

#define HIGH  1
#define LOW   0

#define RES_WRITE     		0x0000
#define MCP48X2_DACB  		(RES_WRITE |(1<<15))
#define MCP48X2_DACA  		(RES_WRITE & ~(1<<14))

#define MCP48X2_GAIN_1X  	(RES_WRITE | (1<<13))
#define MCP48X2_GAIN_2X  	(RES_WRITE & ~(1<<12))

#define MCP48X2_OUTPUT_ON       (RES_WRITE | (1<<12))
#define MCP48X2_OUTPUT_OFF      (RES_WRITE & ~(1<<11))

#define MCP48X2_VREF 2.048

#define MCP48X2 MCP4822

// These pin setting need to be done mannualy by commenting out this if you want to use microcontroller other then PIC.
sbit mcp48x2_cs at RB0_bit;       // connects to CS pin of MCP 48x2
sbit mcp48x2_cs_Dir at TRISB0_bit;
sbit mcp48x2_sck at RB1_bit;      // connects to SCK pin of MCP 48x2
sbit mcp48x2_sck_Dir at TRISB1_bit;
sbit mcp48x2_sdo at RB2_bit;      // connects to SDI pin of MCP 48x2
sbit mcp48x2_sdo_Dir at TRISB2_bit;
sbit mcp48x2_ldac at RB3_bit;      // connects to LDAC pin of MCP 48x2
sbit mcp48x2_ldac_Dir at TRISB3_bit;


extern unsigned int res_config;

void MCP48X2_init();
void MCP48X2_write(float dac_out);
unsigned int Vol2Bitcon(float dac_out);
void MCP48X2_CONFIG(unsigned int channel, unsigned int gain, unsigned int output_enable);
