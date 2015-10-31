#include <cstdio>
#include <cstdlib>

void *leeEnteros(void)
{
  int dato;
  if (scanf("%d",&dato)==EOF) return NULL;
  return (void *) dato;
}

int compEnteros(const void*d1, const void*d2)
{
  return (int) d1 - (int) d2;
}

void imprimeEnteros (void *d)
{
  printf("%d\n",(int)d);
}

void eliminaEnteros(void *d)
{
  
}
