#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "MAX5825BAUP+.h"

//I2C Addresses
char DAC               = 0x1F;
char ADC               = 0x33; 
char currentSensors[4] = {0x4C,0x4D,0x4E,0x4F};
char temperature[11]   = {0x40,0x41,0x42,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B};


//Prototypes
void test_DeviceID();


//Variables
int i = 0;
int address = 0x00;
uint16_t temp_resolution = 1;
int upperByte  = 0;
int lowerByte  = 0;
int data = 0;
int fd[18] = {};

int main(){
  

	wiringPiSetup();
	fd[0]  = wiringPiI2CSetup(0x71);//i2c multiplexer
	fd[1]  = wiringPiI2CSetup(currentSensors[0]);//INA226 #1
	fd[2]  = wiringPiI2CSetup(currentSensors[1]);//INA226 #2
	fd[3]  = wiringPiI2CSetup(currentSensors[2]);//INA226 #3
	fd[4]  = wiringPiI2CSetup(currentSensors[3]);//INA226 #4 

	fd[5]  = wiringPiI2CSetup(DAC);//MAX5825BAUP  DAC
	fd[6]  = wiringPiI2CSetup(ADC);//MAX11615EEE+ ADC

	fd[7]  = wiringPiI2CSetup(temperature[0]);  //TMP1075 #1
	fd[8]  = wiringPiI2CSetup(temperature[1]);  //TMP1075 #2
	fd[9]  = wiringPiI2CSetup(temperature[2]);  //TMP1075 #3
	fd[10] = wiringPiI2CSetup(temperature[3]); //TMP1075 #4
	fd[11] = wiringPiI2CSetup(temperature[4]); //TMP1075 #5
	fd[12] = wiringPiI2CSetup(temperature[5]); //TMP1075 #6
	fd[13] = wiringPiI2CSetup(temperature[6]); //TMP1075 #7
	fd[14] = wiringPiI2CSetup(temperature[7]); //TMP1075 #8
	fd[15] = wiringPiI2CSetup(temperature[8]); //TMP1075 #9
	fd[16] = wiringPiI2CSetup(temperature[9]); //TMP1075 #10
	fd[17] = wiringPiI2CSetup(temperature[10]);//TMP1075 #11
 

  /**
	

  **/
  
 
  

while(1){
  wiringPiI2CWrite(fd[0],0x02); 
  code_load(fd[5],0x01,0xFFFF);
  load(fd[5],0x01);
   
  
  
  wiringPiI2CWrite(fd[0],0x00); 

  usleep(250000);

}
 
}

void test_DeviceID(){
	
	printf("\n\r");
     //INA226 TEST
     wiringPiI2CWrite(fd[0],0x08); 
     data = wiringPiI2CReadReg16(fd[1],0xFF);
     wiringPiI2CReadReg8(fd[0],0x08); 
     	printf("INA226(0x4C)  Device ID: 0x%x\n\r",data );

     wiringPiI2CWrite(fd[0],0x10); 
     data = wiringPiI2CReadReg16(fd[2],0xFF);
     wiringPiI2CReadReg8(fd[0],0x10); 
     	printf("INA226(0x4D)  Device ID: 0x%x\n\r",data );

     wiringPiI2CWrite(fd[0],0x20); 
     data = wiringPiI2CReadReg16(fd[3],0xFF);
     wiringPiI2CReadReg8(fd[0],0x20); 
	printf("INA226(0x4E)  Device ID: 0x%x\n\r",data );

     wiringPiI2CWrite(fd[0],0x40); 
     data = wiringPiI2CReadReg16(fd[4],0xFF);
     wiringPiI2CReadReg8(fd[0],0x40); 
	upperByte = (data & 0xFF00)  >> 8;
	lowerByte = (data & 0x00FF) << 8;
 	printf("INA226(0x4F)  Device ID: 0x%x\n\r",(upperByte + lowerByte) );

//MAX5823 DAC TEST
     wiringPiI2CWrite(fd[0],0x02); 
     data = wiringPiI2CWriteReg16(fd[5],0xB0,0xFF10);
    // wiringPiI2CReadReg8(fd[0],0x02); 

//MAX11615EEE ADC TEST

      wiringPiI2CWrite(fd[0],0x01); 
      wiringPiI2CWrite(fd[6],0x00);

      wiringPiI2CWrite(fd[0],0x04); 
      wiringPiI2CWrite(fd[6],0x00);
    

 //wiringPiI2CReadReg8(fd[0],0x04); 


//Turn off Multiplexer
wiringPiI2CWrite(fd[0],0x00);
      //TMP1075 TEST
      for(i = 0; i < 11; i = i + 1){
	data = wiringPiI2CReadReg16(fd[i + 7],0x0F);
	upperByte = (data & 0xFF00)  >> 8;
	lowerByte = (data & 0x00FF) << 8;
	printf("TMP1075(0x%x) Device ID: 0x%x\n\r",temperature[i],(upperByte + lowerByte) );
      }
	
	
	
	
}