#include <stdio.h>

#define UART_BASE_ADRS 0x40017800 //BU ADRES DONANIMSAL OLARAK AYARLANMISTIR

#define UART_CTRL_REG_OF    0x20
#define UART_STATUS_REG_OF  0x30
#define UART_INT_REG_OF     0x40

#define UART_REG(name) ( (int)UART_BASE_ADRS + UART_##name##_REG_OF)

int main(int argc, char*argv[])
{
	printf("REG CTRL : 0x%08x \n",UART_REG(CTRL));
	printf("REG STATUS : 0x%08x \n",UART_REG(STATUS));

	//*((int*)(REG(CTRL))) = 0x20;//BURADA CTRL REGISTER ICINE 0x20 yazilmaya calisildi.

	return 0;
}
