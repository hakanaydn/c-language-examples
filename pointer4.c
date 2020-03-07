#include <stdio.h>

unsigned char data[10] ={0,1,2,3,4,5,6,7,8,9};

struct sTest1
{
	unsigned char data1;
	unsigned char data2;
};

struct sTest2
{
	unsigned char data3;
	unsigned char data4[7];
};

int main()
{
	struct sTest1 * test1 = (struct sTest1*)&data[0];
	struct sTest2 * test2 = (struct sTest2*)&data[2];


	printf("%d %d \n",test1->data1, test1->data2);
	printf("%d %d %d %d \n",test2->data3, test2->data4[0],test2->data4[1],test2->data4[2]);
	return 0;
}
