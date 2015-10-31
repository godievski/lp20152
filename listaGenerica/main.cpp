/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 6 de octubre de 2015, 09:20 AM
 */

#include "mylist.h"
//#include "funcEnteros.h"
#include "funcParaRegistro.h"

int
main (int argc, char** argv)
{
  void*lista;
  /*
  creaLista(lista, leeEnteros, compEnteros);  
  imprimeLista(lista, imprimeEnteros);
  eliminaLista(lista, eliminaEnteros);
  */
  creaLista(lista, leeReg, compReg);  
  imprimeLista(lista, imprimeReg);
  eliminaLista(lista, eliminaReg);
  
  return 0;
}

