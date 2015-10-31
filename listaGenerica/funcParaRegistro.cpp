#include <cstdio>
#include <cstdlib>
#include <cstring>

void *leeReg (void)
{
  void **reg;
  int cod, *codigo;
  char buff[500], *nombre;
  double *sueldo;
  if (scanf("%d",&cod) == EOF) return NULL;
  codigo = new int;
  *codigo = cod;
  while (getchar()!='\n'); //limpia el buffer
  gets(buff);
  nombre = new char[strlen(buff) + 1];
  strcpy(nombre, buff);
  sueldo = new double;
  scanf("%lf",sueldo);
  reg = new void*[3];
  reg[0] = codigo;
  reg[1] = nombre;
  reg[2] = sueldo;
  return reg;
}

int compReg (const void*r1, const void*r2)
{
  void **reg1 = (void **)r1, **reg2 = (void **)r2;
  int *codigo1 = (int *) reg1[0], *codigo2 = (int *) reg2[0];
  char *nombre1 = (char *) reg1[1], *nombre2 = (char *) reg2[1];
  double *sueldo1 = (double *) reg1[2], *sueldo2 = (double *) reg2[2];
  
  return *codigo1 - *codigo2;  //compara codigos
  //return strcmp(nombre1, nombre2); //compara nombres
  //return *sueldo1 - *sueldo2; //compara sueldos
}

void imprimeReg (void *r)
{
  void **reg = (void **) r;
  int *cod = (int *) reg[0];
  char *nomb = (char *) reg[1];
  double *sueldo = (double *) reg[2];
  printf("Codigo: %d  Nombre: %-20s Sueldo: %10.2lf\n",*cod,nomb,*sueldo);
}

void eliminaReg(void *r)
{
  void **reg = (void **) r;
  int *cod = (int *) reg[0];
  char *nomb = (char *) reg[1];
  double *sueldo = (double *) reg[2];
  
  delete[]cod;
  delete[]nomb;
  delete[]sueldo;
  delete[]reg;
}
