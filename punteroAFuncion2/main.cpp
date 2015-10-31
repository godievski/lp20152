/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 6 de octubre de 2015, 08:16 AM
 */

#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

/*
 * 
 */

int cmpStr (const void*, const void*);

main (int argc, char** argv)
{

  char *nombres[100], buff[100];
  int numDat = 0;
  
  while (gets(buff) != NULL) {
      nombres[numDat] = new char[strlen(buff)+1];
      strcpy(nombres[numDat], buff);
      numDat++;
    }
  
  qsort(nombres, numDat, sizeof(char *), cmpStr);
  for (int i=0; i < numDat; i++)
    printf("%s\n",nombres[i]);
  
  
  return 0;
}

int cmpStr (const void* p1, const void* p2)
{
  char **n1, **n2;
  n1 = (char **) p1;
  n2 = (char **) p2;
  
  return strcmp(*n1,*n2);
}

