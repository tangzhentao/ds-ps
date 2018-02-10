#include <stdio.h>

int main ()
{
	printf ("short int size: %lu\n", sizeof(short int));
	printf ("int size: %lu\n", sizeof(int));
	printf ("long int size: %lu\n", sizeof(long int));
	printf ("float size: %lu\n", sizeof(float));
	printf ("double size: %lu\n", sizeof(double));

	return 0;
}
