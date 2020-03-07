#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef void (*generalFunc)(unsigned char*);

void func_a(unsigned char* data)
{
	printf("%s FUNC IS CALLED \n",data);
}

void func_b(unsigned char* data)
{
	printf("%s FUNC IS CALLED \n",data);
}

void func_c(unsigned char* data)
{
	printf("%s FUNC IS CALLED \n",data);
}

generalFunc general[]=
{
	(generalFunc)func_a,
	(generalFunc)func_b,
	(generalFunc)func_c
};

typedef enum
{
	eAfunc,
	eBfunc,
	eCfunc,
	eLastfunc,
}teFuncIndex;

typedef struct 
{
	unsigned char funcName[10];
	teFuncIndex index;
}tsFunc;

tsFunc sFunc[]={
	{"a",eAfunc},
	{"b",eBfunc},
	{"c",eCfunc},
};


int main(int argc, char*argv[])
{
	//burada aynı tip fonksiyonlar sıra ile calistirildi.

	/*general[0]("a");
	general[1]("b");
	general[2]("c");*/
	if(argc == 1) 
	{
		return -1;
	}
	
	for(unsigned char cnt = 0 ; cnt < eLastfunc; cnt++)
	{
		if(!strcmp(argv[1], sFunc[cnt].funcName) )
		{
			general[sFunc[cnt].index](sFunc[cnt].funcName);
		}
	}
	


	return 0;
}
