#include <stdio.h>

//Bu define ile default acılısı belirlenebilir. 

		/*ID COMM BYTETYPE PAYLOAD VAL*/
#define A_REG    11,12,13,14,15,
#define B_REG    21,22,23,24,25,
#define C_REG    31,32,33,34,35,

#define ABC 10,

#define INIT_REG { \
	A_REG\
	B_REG\
	C_REG\
}\

#define INIT {\
	ABC\
	INIT_REG\
}\

typedef struct
{
	int id;
	int rw;
	int wbyte;
	int format;
	int val;
}OT;

typedef struct 
{
	OT test1;
	OT test2;
	OT test3;
}tsReg;

typedef struct 
{
	int activity;
	tsReg sReg;
}tsDeneme_t;


tsDeneme_t sDeneme [2] = {INIT,INIT};

int main()
{
	printf("A REG -> id : %d \n",sDeneme[0].sReg.test1.id);
	printf("B REG -> id : %d \n",sDeneme[0].sReg.test2.id);
	printf("C REG -> id : %d \n",sDeneme[0].sReg.test3.id);
	return 0;
}
