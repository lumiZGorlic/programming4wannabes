
int f1 (void)
{
  register  int a = 10;
  register  int b = 20;

  a += b;
  return a;
}

int main (void)
{
  int a;
  a = f1();
}

