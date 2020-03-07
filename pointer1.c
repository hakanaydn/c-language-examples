#include <stdio.h>

unsigned char data [10] = {1,2,3,4,5,6,7,8,9,10};

unsigned int adrofdata ;

int main(int argc, char*argv[])
{
	
	adrofdata =(unsigned int)&data[0]; // adres atandı

	printf("ADRS OF DATA : 0x%08x \n", adrofdata);

	printf("DATA[0] : %x \n", *(unsigned char*)(adrofdata + 0));
	printf("DATA[1] : %x \n", *(unsigned char*)(adrofdata + 1));
	printf("DATA[2] : %x \n", *(unsigned char*)(adrofdata + 2));
	printf("DATA[3] : %x \n", *(unsigned char*)(adrofdata + 3));
	printf("DATA[4] : %x \n", *(unsigned char*)(adrofdata + 4));
	return 0;
}
