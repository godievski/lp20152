#include <cstdio>
#include <cstdlib>

void f(int *x){
  for (int i = 0; i < 5; i++)
    printf("%d) %d\n",i, x[i]);
}

int main ()
{
  int *pt;
  int a = 12, b = 45;
  int arr[5] = {1,2,3,4,5};


  pt = &a;
  printf("A = %d\n",*pt);
  *pt = 55;
  printf("A = %d\n",a);


  pt = &arr[2];
  printf("Arr2[0] = %d\n",*pt);
  printf("Arr2[1] = %d\n",pt[1]);

  f(pt);
  return 777;
}
