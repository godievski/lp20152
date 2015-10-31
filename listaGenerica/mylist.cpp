
#include <cstdlib>

void insertarEnLista(void *&,void*, int (*) (const void*, const void*));

/*PUBLIC*/

void creaLista (void*&lista,
                void* (*leeDato) (void),
                int (*compara) (const void*, const void*))
{
  void *reg;
  lista = NULL;
  while (1){
      reg = leeDato();
      if (reg == NULL) break;
      insertarEnLista(lista, reg, compara);
    }
}

void imprimeLista (void *l,
                   void (*imprime)(void *))
{
  void **lista = (void **) l;
  while (lista){
      imprime(lista[0]);
      lista = (void **)(lista[1]);
  }
}

void eliminaLista (void*l,
                   void (*elimina) (void*))
{
  void **lista = (void **) l, **sale;
  while (lista){
      sale = lista;
      lista = (void **)(lista[1]);
      elimina(sale[0]);
      delete[]sale;
  }
}


/*PRIVATE*/
void insertarEnLista(void *&lista,void*reg, int (*compara) (const void*, const void*))
{
  void **p = (void **) lista, **ant = NULL, **nuevo;
  
  nuevo = new void*[2];
  nuevo[0] = reg;
  
  while (p){
      if(compara(p[0], nuevo[0])>0) break;
      ant = p;
      p = (void **) (p[1]);
    }
  nuevo[1] = p;
  if (ant == NULL) lista = nuevo;
  else ant[1] = nuevo;
}



