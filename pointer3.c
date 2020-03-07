#include <stdio.h>

#define len 10

unsigned char data[len];

void show(unsigned int * pBuf)
{
	for(unsigned char say = 0; say < len ; say++)
	{
  		printf("%x \n", *((unsigned char*)(pBuf) + say));//data ya ulasıldı
	}	
}	

int main()
{
	unsigned int adres;

	for(unsigned char say = 0; say < len ; say++)
	{
		data[say]=say;
	}
	
	adres =&data[0];//datanın adresi bir degiskene atıldı

	show((unsigned int*)adres);

	return 0;
}
