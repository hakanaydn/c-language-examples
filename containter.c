#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
 
#define container_of(ptr, type, member) ({         \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) );})

struct deneme {
	unsigned char val1;
	unsigned char val2;
	unsigned char val3;
	unsigned char val4;
	unsigned char val5;
	unsigned char val6;
};

void show(unsigned char * adres)
{
  struct deneme* st = container_of(adres, struct deneme, val1 );

  printf("VAL 2 : %x\n", st->val2);

}


int main()
{
	struct deneme test;
	
	test.val1 = 1;
	test.val2 = 2;
	test.val3 = 3;
	test.val4 = 4;
	test.val5 = 5;
	test.val6 = 6;

	printf("ADRES STRUCT : 0x%08x \n", &test);
	printf("Container ADRES STRUCT : 0x%08x \n", container_of(&test.val1, struct deneme, val1 ) );

	show(&test.val1);


	return 0;
}
