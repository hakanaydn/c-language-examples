#include <stdio.h>


/////////////////////BURASI AYRI YERDE///////////////////////
struct sData
{
	unsigned char data[1500];
};

typedef struct 
{
	void (*pfn)(struct sData*);
}tsInit;

tsInit sInit;

void init(void(*pfn_func)(struct sData*))
{
	sInit.pfn = *pfn_func;
}

void interrupt()
{
	struct sData da;
	da.data[0]=20;
	sInit.pfn(&da);
}
///////////////////////////////////////////////////////////////

void callback(struct sData* pBuf)
{
	printf("%d \n",pBuf->data[0]);
}

int main(int argc, char *argv[])
{
	init(callback);

	//normalde bu fonskiyon hardware yakın yerde cagırlır
	interrupt();

	return 0;
}
