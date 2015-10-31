#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include "mylib.h"

#define INCREMENTO 5

/******************************************************************/
void leerDatos (void *&cursos, void *&alumnos)
{
  int codAlum;
  
  /*LECTURA DE CURSOS*/
  void **buffCursos = new void*[500], *reg;
  int cantCur = 0;
  
  while (1){
      if ((reg = leeCurso(codAlum)) == NULL) break;
      buffCursos[cantCur] = reg;
      cantCur++;
    }
  
  void **arrayCur = new void*[cantCur+1];
  for (int i = 0; i < cantCur; i++)
      arrayCur[i] = buffCursos[i];
  arrayCur[cantCur] = NULL;
  cursos = arrayCur;
  //printCursos(cursos);
  
  /*LECTURA DE ALUMNOS*/
  int primera = true;
  void *buffAlum[500];
  int cantAlum = 0;
  while (1){
      if (!primera)
        if (scanf("%d", &codAlum) == 0) break;
      buffAlum[cantAlum] = leeAlumno(codAlum);
      cantAlum++;
      primera = false;
    }
  void **arrayAlum = new void*[cantAlum+1];
  for (int i = 0; i < cantAlum; i++)
    arrayAlum[i] = buffAlum[i];
  arrayAlum[cantAlum] = NULL;
  alumnos = arrayAlum;
  //printAlumnos(alumnos);
}

void * leeCurso (int &codAlum)
{
  char linea[500], buffNomb[200], *nomb, *cod;
  char *palabras[50];
  int cantPal = 0;
  double *creditos;
  
  if (scanf("%d",&codAlum)) return NULL; //lee el codigo de un alumno
  gets(linea); //lee todo el curso
  separaPalabras(linea, palabras, cantPal); //lo separa en palabras
  
  cod = new char[strlen(palabras[0])+1];
  strcpy(cod, palabras[0]); //separa memoria para el cod del curso
  
  strcpy(buffNomb, palabras[1]);
  for (int i = 2; i < cantPal - 1; i++){
      strcat(buffNomb, " ");
      strcat(buffNomb, palabras[i]);
    }
  nomb = new char[strlen(buffNomb)+1];
  strcpy(nomb, buffNomb); //separa memoria para el nombre del curso
  
  creditos = new double;
  *creditos = atof(palabras[cantPal-1]); //separa memoria para los creditos
  
  void **reg = new void*[3];
  reg[0] = cod;
  reg[1] = nomb;
  reg[2] = creditos;
  
  return reg;
}

void * leeAlumno(int codAlum)
{
  char linea[500], buffNomb[200], *nomb;
  char *palabras[50];
  int cantPal = 0;
  int *codFac;
  int *cod;
  
  gets(linea);
  separaPalabras(linea, palabras, cantPal);
  
  strcpy(buffNomb, palabras[0]);
  for (int i = 1; i < cantPal - 1; i++){
      strcat(buffNomb, " ");
      strcat(buffNomb, palabras[i]);
    }
  nomb = new char[strlen(buffNomb) + 1];
  strcpy(nomb, buffNomb);
  
  cod = new int;
  *cod = codAlum;
  
  codFac = new int;
  *codFac = atoi(palabras[cantPal-1]);
  
  void **reg = new void*[4];
  reg[0] = cod;
  reg[1] = nomb;
  reg[2] = codFac;
  reg[3] = NULL;
  
  return reg;
}

/******************************************************************/
void agregarNotas(void *alumnos)
{
  char *codCur;
  int codAlum;
  int nota;
  
  agregarListaNota(alumnos);

  while (1){
      if ((codCur = leePalabra()) == NULL) break;
      scanf("%d",&codAlum);
      scanf("%d",&nota);
      char c;
      while ((c =getchar()) != '\n');
      agregarUnaNota(alumnos, codCur, codAlum, nota);
    }
  //printAlumnosConNota(alumnos);
}

char * leePalabra (void)
{
  char buffer[100];
  char c;
  int tam = 0;

  c = getchar();
  if (isblank(c)) return NULL;
  buffer[0] = c;
  tam++;
  while (1){
      c = getchar();
      if (isblank(c)) break;
      buffer[tam] = c;
      tam++;
    }
  buffer[tam] = 0;
  
  char *cod = new char[tam+1];
  strcpy(cod, buffer);
  return cod;
}

void agregarListaNota (void *alumnos)
{
  void **arrayAlum = (void **) alumnos;
  void **reg;
  int *codAlum;
  char *nombAlum;
  int * codFac;
  char **listaCur;
  int *listaNota;
  int *descLista;
  
  for (int i = 0; arrayAlum[i]; i++){
      reg = (void **) arrayAlum[i];
      codAlum = (int *) reg[0];
      nombAlum = (char *) reg[1];
      codFac = (int *) reg[2];
      delete reg;
      reg = new void*[6];
      reg[0] = codAlum;
      reg[1] = nombAlum;
      reg[2] = codFac;
      listaCur = new char*[INCREMENTO];
      listaCur[0] = NULL;
      listaNota = new int[INCREMENTO];
      listaNota[0] = -1;
      descLista = new int[2];
      descLista[0] = INCREMENTO;
      descLista[1] = 1;
      reg[3] = listaCur;
      reg[4] = listaNota;
      reg[5] = descLista;
      arrayAlum[i] = reg;
    }
}

void agregarUnaNota (void *alumnos, char *codCur, int codAlum, int nota)
{
  void **arrayAlum = (void **) alumnos;
  void **reg;
  int indAlum, indCur;
  char **listaCur;
  int *listaNota;
  int *descLista;
  
  indAlum = buscaAlumno(alumnos, codAlum);
  reg = (void **) arrayAlum[indAlum];
  
  listaCur = (char **) reg[3];
  indCur = buscaCurso (listaCur, codCur);
  
  if (listaCur[indCur] != NULL){
      listaNota = (int *) reg[4];
      if (listaNota[indCur] <= nota)
        listaNota[indCur] = nota;
  } else{
      descLista = (int *) reg[5];
      if (descLista[0] == descLista[1])
        aumentarTamLista(alumnos, indAlum);
      reg = (void **) arrayAlum[indAlum];
      listaCur = (char **) reg[3];
      listaNota = (int *) reg[4];
      descLista = (int *) reg[5];
      listaCur[indCur] = codCur;
      listaCur[indCur+1] = NULL;
      listaNota[indCur] = nota;
      listaNota[indCur+1] = -1;
      (descLista[1])++;
  }
}

int buscaAlumno (void *alumnos, int codAlum)
{
  int ind = 0;
  void **arrayAlum = (void **) alumnos;
  void **reg;
  int *cod;
  
  for(ind = 0; arrayAlum[ind]; ind++){
      reg = (void **) arrayAlum[ind];
      cod = (int *) reg[0];
      if (*cod == codAlum) break;
    }

  return ind;
}

int buscaCurso (char **listaCur, char *codCur)
{
  int ind = 0;
  
  for (ind = 0; listaCur[ind]; ind++){
      if (strcmp(listaCur[ind], codCur) == 0) break;
    }
  return ind;
}

void aumentarTamLista(void *alumnos, int indAlum)
{
  void **arrayAlum = (void **) alumnos;
  void **reg = (void **) arrayAlum[indAlum];
  int *descLista = (int *) reg[5];
  char **auxListaC, **listaCur = (char **) reg[3];
  int *auxListaN, *listaNota = (int *) reg[4];
  
  descLista[0] += INCREMENTO;
  auxListaC = new char*[descLista[0]];
  auxListaN = new int[descLista[0]];
  for (int i = 0; i < descLista[1]; i++){
      auxListaC[i] = listaCur[i];
      auxListaN[i] = listaNota[i];
    }
  delete listaCur;
  delete listaNota;
  reg[3] = auxListaC;
  reg[4] = auxListaN;
}

/******************************************************************/
void separacionDeEgresados (void *cursos, void *&alumnos, void *&egresados)
{
  int codFac;
  char *nombFac;
  double credFac;
  void *buffAlumnos[500], **arrayAlum = (void **) alumnos;
  void *buffEgresados[500];
  int cantAlum = 0, cantEgre = 0;
  
  while (scanf("%d",&codFac) != EOF){
      scanf("%*d"); //elimina espacios en blanco
      leeNombYCredFac(nombFac, credFac);
      buffEgresados[cantEgre] = nombFac;
      cantEgre++;
      for (int i = 0; arrayAlum[i]; i++){
          void **reg = (void **) arrayAlum[i];
          int *alumCodFac = (int *) reg[2];
          if (codFac == *alumCodFac){
              double credAprob = calcCredAprob(reg, cursos);
              if (credAprob >= credFac)
                  agregaEgresado(buffEgresados, cantEgre, reg);
              else{
                  buffAlumnos[cantAlum] = reg;
                  cantAlum++;
              }
          }
      }
      buffEgresados[cantEgre] = NULL;
      cantEgre++;
    }
  buffEgresados[cantEgre] = buffAlumnos[cantAlum] = NULL;
  
  delete[]arrayAlum;
  
  void **arrayEgre = new void*[cantEgre+1];
  for (int i = 0; i <= cantEgre; i++)
      arrayEgre[i] = buffEgresados[i];
  egresados = arrayEgre;
  
  void **auxAlum = new void*[cantAlum+1];
  for (int i = 0; i <= cantAlum; i++)
    auxAlum[i] = buffAlumnos[i];
  alumnos = auxAlum;
  
  printEgresados(egresados);
  putchar('\n');
  printNChar('=',80);
  printAlumnos(alumnos);
}

void leeNombYCredFac(char *&nombFac, double &credFac)
{
  char linea[200];
  char *palabras[50];
  int cantPal = 0;
  char buffNomb[100];
  
  gets(linea);
  separaPalabras(linea, palabras, cantPal);
  strcpy(buffNomb, palabras[0]);
  for (int i = 1; i < cantPal - 1; i++){
      strcat(buffNomb, " ");
      strcat(buffNomb, palabras[i]);
    }
  nombFac = new char[strlen(buffNomb) + 1];
  strcpy(nombFac, buffNomb);
  
  credFac = atof(palabras[cantPal-1]); 
}

double calcCredAprob (void **regAlum, void *cursos)
{
  char **listaCur = (char **) regAlum[3];
  int *listaNotas = (int *) regAlum[4];
  double credAprob = 0, credCur;
  
  for (int i = 0; listaCur[i]; i++){
      credCur = buscaCredCurso(cursos, listaCur[i]);
      if (listaNotas[i] >= 11)
        credAprob += credCur;
    }
  return credAprob;
}

double buscaCredCurso(void *cursos, char *codCurso)
{
  void **arrayCur = (void **) cursos;
  void **reg;
  double *cred;
  char *codigo;
  
  for (int i = 0; arrayCur[i]; i++){
      reg = (void **) arrayCur[i];
      codigo = (char *) reg[0];
      cred = (double *) reg[2];
      if (strcmp(codigo, codCurso) == 0) return *cred;
  }
  return 0;
}

void agregaEgresado(void **buffEgresados, int &cantEgre, void **reg)
{
  void **nuevoReg = new void*[2];
  
  char *nomb = (char *) reg[1];
  char *nuevoNomb = new char[strlen(nomb)+1];
  strcpy(nuevoNomb,nomb);
  
  int *cod = (int *) reg[0];
  int *nuevoCod = new int;
  *nuevoCod = *cod;
  
  nuevoReg[0] = nuevoCod;
  nuevoReg[1] = nuevoNomb;
  
  buffEgresados[cantEgre] = nuevoReg;
  cantEgre++;
}

void separaPalabras(char *linea,char **palabras, int &cantPal)
{
  cantPal = 0;
  
  if (!isblank(linea[0])){
      palabras[0] = linea;
      cantPal++;
    }
  
  for (int i = 1; linea[i]; i++){
      if (!isblank(linea[i]) && (isblank(linea[i-1]) || linea[i-1] == 0 )){
          palabras[cantPal] = &(linea[i]);
          cantPal++;
        }
      
      if (!isblank(linea[i]) && isblank(linea[i+1])){
          linea[i+1] = 0;
          i++;
        }
    }
}

void printCursos(void *cursos)
{
  void **arrayCur = (void **) cursos;
  void **reg;
  char *nomb,*cod;
  double *cred;
  
  for (int i = 0; arrayCur[i]; i++){
      reg = (void **) arrayCur[i];
      cod = (char *) reg[0];
      nomb = (char *) reg[1];
      cred = (double *) reg[2];
      printf("%-8s %-50s %2.1lf\n",cod,nomb,*cred);
    }
}

void printAlumnos (void *alumnos)
{
  void **arrayAlum = (void **) alumnos;
  void **reg;
  int *cod, *codFac;
  char *nomb;
  
  for (int i = 0; arrayAlum[i]; i++){
     reg = (void **) arrayAlum[i];
     cod = (int *) reg[0];
     nomb = (char *) reg[1];
     codFac = (int *) reg[2];
     printf("%-10d %-50s %-10d\n",*cod, nomb, *codFac);
    }
}

void printAlumnosConNota(void *alumnos)
{
  void **arrayAlum = (void **) alumnos;
  void **reg;
  int *codAlum, *codFac;
  char *nombAlum;
  char **listaCur;
  int *listaNota;
  
  for (int i = 0; arrayAlum[i]; i++){
      reg = (void **) arrayAlum[i];
      printNChar('*',80);
      codAlum = (int *) reg[0];
      nombAlum = (char *) reg[1];
      codFac = (int *) reg[2];
      printf("Codigo: %d  Nombre: %-40s %d\n",*codAlum,nombAlum,*codFac);
      listaCur = (char **) reg[3];
      listaNota = (int *) reg[4];
      printf(" N° Cod.Curso   Nota\n");
      for (int j = 0; listaCur[j]; j++)
        printf("%02d)  %-10s  %02d\n",j+1,listaCur[j],listaNota[j]);
    }
}

void printEgresados(void *egresados)
{
  void **arrayEgre = (void **) egresados;
  int i=0;
  while (1){
    char *nombFac = (char *) arrayEgre[i];
    printNChar('*',50);
    printf("FACULTAD: %s\n",nombFac);
    i++;
    int j = 1;
    while (1){
        if (arrayEgre[i] == NULL){
            if (arrayEgre[i+1] == NULL) return;
            else{
                i++;
                break;
            }
        }
        void **reg = (void **) arrayEgre[i];
        int *cod = (int *) reg[0];
        char *nomb = (char *) reg[1];
        printf("%02d) %-10d %s\n",j,*cod,nomb);
        j++;
        i++;
    }
  }
}

void printNChar(char c, int n, int ln)
{
  for (int i = 0; i < n; i++)
    putchar(c);
  if (ln) putchar('\n');
}
