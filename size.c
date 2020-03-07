#include <stdio.h>

typedef struct 
{
	unsigned char x;
	unsigned char y;
	unsigned char z;
}Stest;

Stest test [] = {
	{1,2,3},
	{3,4,5},
	{5,6,7},
	{8,9,1},
	{8,9,1},	
	{8,9,1},		
};

int main()
{
	printf("%d %d \n",sizeof(test),sizeof(Stest));
	
	printf("TOPLAN ELEMAN SAYISI: %d \n",sizeof(test)/sizeof(Stest));
	return 0;	
}
