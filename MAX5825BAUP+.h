#include <stdint.h>



/**
UCLA GAPS:
C Library for MAX5825BAUP+ DAC used for HV
Channel 0: 
Channel 1: 
Channel 2: 
Channel 3: 
Channel 4: 
Channel 5: 
Channel 6: 
Channel 7: 

Write to I2C Expander then follow with the following functions

**/

struct MAX5825_DAC{
	uint16_t address;
	uint16_t channel;
	uint16_t voltage;
};
 
/**
Configuration Registers


MAX5825BAUP+ Datasheet
https://datasheets.maximintegrated.com/en/ds/MAX5823-MAX5825.pdf
**/


/**
DAC_pwr(uint16_t,uint16_t,int);
	uint16_t address    	 : DAC i2c address
	uint16_t channel    	 : DAC channel 7-0             
	int 	 mode            : PWR Mode
                               00: Normal Mode
                               01: Power down with 1kOhm termination to GND
                               10: Power down with 100kOhm termination to GND
                               11: Power down with Hi-Z
**/
void DAC_pwr(uint16_t address, uint16_t channel,int mode);
 
/**
Dac_config(uint16_t,uint16_t,int,int,int,int);
	uint16_t address    	 : DAC i2c address
	uint16_t channel    	 : DAC channel 7-0
	int 	 watchdogConfig  : WDOG config
                            	   00:DIS
                                   01:GATE
                                   10:CLR
                                   11:HOLD
	int 	 gateEnb         : Gate Configuration
                                   0:Enables  software gating function 
                                   1:Disables software gating function 
	int 	 ldacEnb         : Load Configuration
                                   0:Enables   DAC latch(LDAC and Load functions)
                                   1:Disables  DAC latch(LDAC and Load functions)
	int 	 clearEnb        : Clear Configuration
                                   0:Clear input and command functions impact the DAC
                                   1:Clear input and command functions does not impact the DAC
**/

uint16_t DAC_config(uint16_t address, uint16_t channel,int watchdogConfig,int gateEnb,int ldacEnb,int clearEnb);


/**
DAC Registers

**/

//Function updates contents of CODE register
uint16_t code(uint16_t address, uint16_tnt16_t channel,uint16_t voltage);

//Function loads contents of CODE register to DAC register
uint16_t load(uint16_t address, uint16_tnt16_t channel);

//Function updates CODE register and loads to DAC register
uint16_t code_load(uint16_t address, uint16_tnt16_t channel,uint16_t voltage);

//Function updates CODE register and loads to DAC register
uint16_t codeAll_loadAll(uint16_t address,uint16_t voltage);




