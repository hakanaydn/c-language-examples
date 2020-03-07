#include <stdio.h>

unsigned char ethbuf[10];

int main()
{
	unsigned char * pBuf;

	for(unsigned short x = 0; x < 10; x++)
	{
		ethbuf[x]=0xFF;//raw data doldururuldu	
	}


	pBuf = ethbuf + 2; //pBuf baslangıc adresi ethBuf adresinin 2 byte ötesi atandı.

	*(pBuf) = 0x30;

	printf("ethBuf[%d] : %x \n",2,*(pBuf));	

	return 0;
}
