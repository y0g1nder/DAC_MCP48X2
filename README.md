# DAC_MCP48X2
This repository contains the MCP48X2 series interfacing code in c

To use the file code kindly define the i/o pins you are using to interface the ic. MCP48X2 series requires 4 pins. the code file contains mainly three functions to use. the explaination is written below and uses are shown in example file.

you have to edit define the ic you are using from below statement as i am using mcp4822 here.

#define MCP48X2 MCP4822


these are the four pins you need to define with there respected resister values as i am using pic18f so TRIS AND PORT resistors are used.

sbit mcp48x2_cs at RB0_bit;       // connects to CS pin of MCP 48x2
sbit mcp48x2_cs_Dir at TRISB0_bit;
sbit mcp48x2_sck at RB1_bit;      // connects to SCK pin of MCP 48x2
sbit mcp48x2_sck_Dir at TRISB1_bit;
sbit mcp48x2_sdo at RB2_bit;      // connects to SDI pin of MCP 48x2
sbit mcp48x2_sdo_Dir at TRISB2_bit;
sbit mcp48x2_ldac at RB3_bit;      // connects to LDAC pin of MCP 48x2
sbit mcp48x2_ldac_Dir at TRISB3_bit;


Here three functions you can use :

void MCP48X2_init();          // this function is to initialize the pins as output or input if you are using microcontroller                                   //other than pic you have to mannualy initalize the pins and ignore this function



void MCP48X2_CONFIG(unsigned int channel, unsigned int gain, unsigned int output_enable);  
// This funciton is used to setting up the control resister as which channel you want to use, gain settings and output enable or //disable.

void MCP48X2_write(float dac_out); // This function is used to write down specific voltage value you want to set as output.

a example file is attached to see its use.
