#include <stdio.h>

//AM335X SPI0 REGSITER
//offset 0x000 REVISION  32 bit
//offset 0x110 SYSCONFIG 32 bit
//offset 0x114 SYSSTATUS 32 bit
//offset 0x118 IRQSTATUS 32 bit
//offset 0x11C IRQENABLE 32 bit

#define SPI_BASE_ADRS 0x48030100

struct spi_ch // 4 adet spi channel var
{
	unsigned int conf;
	unsigned int stat;
	unsigned int ctrl;
	unsigned int tx;
	unsigned int rx;
};

struct spi_reg
{
	unsigned char reserved [0x10]; //ilk 0x10 byte korunumludur.
 	unsigned int  sysconfig;//0x48030110
	unsigned int  sysstatus;//0x48030114
	unsigned int  irqstatus;//0x48030118
 	unsigned int  irqenable;//0x4803011C
	unsigned int  wakeupenable;//0x48030124
	unsigned int  syst;//0x48030128
 	unsigned int  modulctrl;
	struct spi_ch ch[4];//4 kanal spi mevcuttur
};

typedef struct 
{
	 unsigned int autoidle  	: 1; 
	 unsigned int softreset 	: 1;
	 unsigned int res1		: 1;
	 unsigned int sidleMode 	: 2;
	 unsigned int res2      	: 3;
	 unsigned int clockactivity 	: 2;
	 unsigned int res3      	: 22; 			
}tsRegSysConfig;

typedef union 
{
   tsRegSysConfig sRegSysConfig; 
   unsigned int sysconfig; 		
}teRegSysConfig;

teRegSysConfig eRegSysConfig;

int main(int argc, char * argv[])
{
	struct spi_reg * spi = (struct spi_reg *) SPI_BASE_ADRS;
	eRegSysConfig.sysconfig = 0x00000001;

	printf("%d \n",eRegSysConfig.sRegSysConfig.autoidle);
	printf("%d \n",eRegSysConfig.sRegSysConfig.softreset);
	printf("%d \n",eRegSysConfig.sRegSysConfig.sidleMode);
	printf("%d \n",eRegSysConfig.sRegSysConfig.clockactivity);

	/*	
		eRegSysConfig.sysconfig = read(&spi->sysconfig);
		if(eRegSysConfig.sysconfig.autoidle)
		{
			eRegSysConfig.sysconfig.autoidle = 0;
		}

	*/

   
	return 0;
}
