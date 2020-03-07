#include <stdio.h>

typedef struct 
{
	unsigned short vala : 4 ;
	unsigned short valb : 4 ;
	unsigned short valc : 4 ;
	unsigned short vald : 4 ;
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
		 
   printf("VAL A : %x \n",eAll.sParse.vala);
   printf("VAL B : %x \n",eAll.sParse.valb);
   printf("VAL C : %x \n",eAll.sParse.valc);
   printf("VAL D : %x \n",eAll.sParse.vald);

   return 0;
}
