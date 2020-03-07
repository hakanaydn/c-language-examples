#include <stdio.h>


/////////////////////BURASI AYRI YERDE///////////////////////
typedef struct 
{
	void (*pfn)(void*);
}tsInit;

tsInit sInit;

void init(void(*pfn_func)(void*))
{
	sInit.pfn = *pfn_func;
}

void interrupt()
{
	unsigned char da[100];
	da[0]=30;
	sInit.pfn(&da);
}
///////////////////////////////////////////////////////////////

void callback(void * data)//bu fonksiyon hardware yakın yede bir interrupt meydana gelirse buraya dallanır
{
	unsigned char * veri = data;

	printf("%d \n",*(veri));
}

int main(int argc, char *argv[])
{
	init(callback);

	//normalde bu fonskiyon hardware yakın yerde cagırlır
	interrupt();

	return 0;
}
