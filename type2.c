#include <stdio.h>

typedef struct 
{
	unsigned short bit0 : 1 ;
	unsigned short bit1 : 1 ;
	unsigned short bit2 : 1 ;
	unsigned short rsv  : 13 ;
}tsParse;

typedef union
{
	unsigned short alls;
	tsParse sParse;
}teAll;

teAll eAll;

int main()
{
   eAll.alls = 0xb872;
		 
   printf("VAL A : %x \n",eAll.sParse.bit0);
   printf("VAL B : %x \n",eAll.sParse.bit1);
   printf("VAL C : %x \n",eAll.sParse.bit2);


   return 0;
}
