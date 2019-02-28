#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

char temperature[11] = {0x40,0x41,0x42,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B};

int i = 0;
int address = 0x00;  
int main(){
int fd[11] = {};
int temp_resolution = 1;
wiringPiSetup();

for(i = 0; i < 11; i = i + 1){
	fd[i] = wiringPiI2CSetup(temperature[i]);
}while(1){


printf("====================================================\n\r");
printf("Temperature0: %d \n\r",wiringPiI2CReadReg16(fd[0],address));
printf("Temperature1: %d  \n\r",wiringPiI2CReadReg16(fd[1],address));
printf("Temperature2: %d \n\r",wiringPiI2CReadReg16(fd[2],address));
printf("Temperature3: %d\n\r",wiringPiI2CReadReg16(fd[3],address));
printf("Temperature4: %d \n\r",wiringPiI2CReadReg16(fd[4],address));
printf("Temperature5: %d \n\r",wiringPiI2CReadReg16(fd[5],address));
printf("Temperature6: %d\n\r",wiringPiI2CReadReg16(fd[6],address));
printf("Temperature7: %d \n\r",wiringPiI2CReadReg16(fd[7],address));
printf("Temperature8: %d\n\r",wiringPiI2CReadReg16(fd[8],address));
printf("Temperature9: %d \n\r",wiringPiI2CReadReg16(fd[9],address));
printf("Temperature10:%d\n\r",wiringPiI2CReadReg16(fd[10],address));
printf("====================================================\n\r\n\r");
usleep(250000);
}
}