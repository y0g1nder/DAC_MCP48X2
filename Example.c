#define MCP48X2 MCP4822  // mcp4822 is used here

sbit mcp48x2_cs at RB0_bit;       // connects to CS pin of MCP 4822
sbit mcp48x2_cs_Dir at TRISB0_bit;
sbit mcp48x2_sck at RB1_bit;      // connects to SCK pin of MCP 4822
sbit mcp48x2_sck_Dir at TRISB1_bit;
sbit mcp48x2_sdo at RB2_bit;      // connects to SDI pin of MCP 4822
sbit mcp48x2_sdo_Dir at TRISB2_bit;
sbit mcp48x2_ldac at RB3_bit;      // connects to LDAC pin of MCP 4822
sbit mcp48x2_ldac_Dir at TRISB3_bit;


void main()
{
// you need to put our microcontroller initialization settings here



    MCP48X2_init();  // if you are using ic other than pic you need to mannaly define 4 i/o with same name as output pins
    
    MCP48X2_CONFIG(MCP48X2_DACA, MCP48X2_GAIN_1X, MCP48X2_OUTPUT_ON); // channel DACA is used with 1x gain and output is enabled
    MCP48X2_write(1.2); // output voltage is set to 1.2V
    
    MCP48X2_CONFIG(MCP48X2_DACA, MCP48X2_GAIN_2X, MCP48X2_OUTPUT_ON); // channel DACA is used with 2x gain and output is enabled
    MCP48X2_write(3.2); // output voltage is set to 3.2V
    
    MCP48X2_CONFIG(MCP48X2_DACB, MCP48X2_GAIN_1X, MCP48X2_OUTPUT_ON); // channel DACB is used with 1x gain and output is enabled
    MCP48X2_write(1.5); // output voltage is set to 1.5V
    
    MCP48X2_CONFIG(MCP48X2_DACB, MCP48X2_GAIN_2X, MCP48X2_OUTPUT_ON); // channel DACB is used with 2x gain and output is enabled
    MCP48X2_write(3.2); // output voltage is set to 3.2V
    
   MCP48X2_CONFIG(MCP48X2_DACB, MCP48X2_GAIN_2X, MCP48X2_OUTPUT_OFF); // channel DACB is used with 2x gain and output is Disabled
   MCP48X2_write(3.2); // output voltage is set to 3.2V 
    
    

}
