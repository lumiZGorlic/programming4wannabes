#include <stdio.h>

// adjusted the values of SIZE and OFF to just dump the
// interesting part for this example
#define SIZE 13
#define OFF  12

void func (char *a) {
  long  first=0x1122334455667788;
  char s[50];
  char *d=s;
  int i;
  long *p;

  // dump stack
  p = (&first) + OFF;
  for (i = 0; i < SIZE; p--,i++)
      printf ("%p -> %0lx\n", p, *p);

  // overwrite
  while (*d++ = *a++);

  // dump stack
  p = (&first) +OFF;
  printf ("---------\n");
  for (i = 0; i < SIZE; p--,i++)
      printf ("%p -> %0lx\n", p, *p);
  
}

int main (int argc, char *argv[]) {
  printf ("Return address: %p\n----\n", &&the_end);
  func (argv[1]);
 the_end:
  return 0;
}
