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


int main(int argc, char * argv[])
{
	struct spi_reg * spi = (struct spi_reg *) SPI_BASE_ADRS;

        printf("1. sysconfig REG ADRS : 0x%08x \n",&spi->sysconfig);
        printf("2. sysstatus REG ADRS : 0x%08x \n",&spi->sysstatus);	
	printf("3. irqstatus ENABLE REG ADRS : 0x%08x \n",&spi->irqstatus);
	printf("4. irqenable ENABLE REG ADRS : 0x%08x \n",&spi->irqenable);
	printf("5. syst ENABLE REG ADRS : 0x%08x \n",&spi->syst);
	printf("6. modulctrl ENABLE REG ADRS : 0x%08x \n",&spi->modulctrl);
	printf("7. 0.ch tx REG ADRS : 0x%08x \n",&spi->ch[0].tx);
	return 0;
}
