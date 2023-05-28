#include <stdio.h>
int main ()
{
//	printf ("Size of void*  : %ld\n", sizeof(void*));
//	printf ("Size of short  : %ld\n", sizeof(short));
//	printf ("Size of int    : %ld\n", sizeof(int));
//	printf ("Size of long   : %ld\n", sizeof(long));
//	printf ("Size of float  : %ld\n", sizeof(float));
//	printf ("Size of double : %ld\n", sizeof(double));


    double d = 8.5667;
    double* dp = &d;
    printf("ad1 %p \n", dp);
    dp += 1;
    // double* is 8 bytes long so it'll increase by 8
    printf("ad1 %p \n", dp);

	return 0;
}
