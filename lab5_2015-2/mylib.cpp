/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "mylib.h"


/*CONSTANTES*/
#define INCREMENTO 5
#define MAX_BUFFER 500 //maxima cantidad para el buffer de un string
#define MAX_PALABRAS 50 //maxima palabras en una linea
#define MAX_CURSOS 100 //maximo cursos por alumnos

void leerCursos (void *&cursos)
{
    void *bufferCursos[MAX_BUFFER];
    int cantCur;
    char *nombCurso;
    char *codigo;

    cantCur = 0;
    while (1){
        if (leeUnCurso(codigo, nombCurso) == NULL) break;
        agregarCurso(bufferCursos, cantCur, codigo, nombCurso);
    }
    
    void **arrayCursos = new void*[cantCur+1];
    for (int i = 0; i < cantCur; i++)
        arrayCursos[i] = bufferCursos[i];
    arrayCursos[cantCur] = NULL;
    cursos = arrayCursos;
}

void * leeUnCurso(char *&codigo, char *&nombCur)
{
    char linea[MAX_BUFFER];
    char *palabras[MAX_PALABRAS];
    char bufferNomb[MAX_BUFFER];
    int cantPal;
    
    gets(linea);
    if (strcmp(linea,"0") == 0) return NULL; //Se encontró el 0, fin de cursos
    
    separaPalabras(linea, palabras, cantPal);
    
    codigo = new char[strlen(palabras[0]) + 1];
    strcpy(codigo,palabras[0]);
    
    strcpy(bufferNomb, palabras[1]);
    for (int i = 2; i < cantPal; i++){
        strcat(bufferNomb, " ");
        strcat(bufferNomb, palabras[i]);
    }
    nombCur = new char[strlen(bufferNomb) + 1];
    strcpy(nombCur, bufferNomb);
}

void agregarCurso(void **bufferCursos, int &cantCur, char *codigo, char *nombCurso)
{
    void **reg = new void*[2];
    
    reg[0] = codigo;
    reg[1] = nombCurso;

    bufferCursos[cantCur] = reg;
    
    cantCur++;
}


void separaPalabras(char *linea, char **palabras, int &cantPal)
{
    cantPal = 0;
    
    if (!isblank(linea[0])){
        palabras[0] = linea;
        cantPal++;
    }
    
    for (int i = 1; linea[i]; i++){
        if (!isblank(linea[i]) && ( isblank(linea[i-1]) || linea[i-1] == 0 ) ){
            palabras[cantPal] = &linea[i];
            cantPal++;
        }
        
        if (!isblank(linea[i]) && isblank(linea[i+1])){
            linea[i+1] = 0;
            i++;
        }
    }
}

void leeMatricula (void *&cursos)
{
    char *nombre, *cursosAlum[MAX_CURSOS];
    int codigo, cantCurAlum;
    int cantDatXCur[MAX_BUFFER];
    int tamXCur[MAX_BUFFER];
    
    //Agrega los dos elementos a cada curso para manejar las listas
    aumentarDosElementosCursos(cursos);

    while (1) {
        if (leeAlumno (codigo,nombre, cursosAlum, cantCurAlum) == NULL) break;
        agregarAlumno (cursos, codigo, nombre, cursosAlum, cantCurAlum, cantDatXCur, tamXCur);
    }
}

void aumentarDosElementosCursos(void *cursos)
{
    void **auxReg, **reg;
    void **arrayCursos = (void **)cursos;
    
    for (int i = 0; arrayCursos[i]; i++){
        reg = (void **) arrayCursos[i];
        auxReg = new void*[4];
        auxReg[0] = reg[0];
        auxReg[1] = reg[1];
        auxReg[2] = auxReg[3] = NULL;
        arrayCursos[i] = auxReg;
        delete[] reg;
    }
}

void * leeAlumno (int &codigo, char *&nombre, char **cursosAlum, int &cantCurAlum)
{
    char linea[MAX_BUFFER];
    char *palabras[MAX_PALABRAS];
    int cantPal;
    
    if (gets(linea) == NULL) return NULL; //si llegó al fin de archivo, termina
    
    separaPalabras(linea, palabras, cantPal);
    
    codigo = atoi(palabras[0]);
    
    nombre = new char[strlen(palabras[1]) + 1];
    strcpy(nombre, palabras[1]);
    
    cantCurAlum = 0;
    for (int i = 2; i < cantPal; i++){
        cursosAlum[cantCurAlum] = new char[strlen(palabras[i]) + 1];
        strcpy(cursosAlum[cantCurAlum], palabras[i]);
        cantCurAlum++;
    }
}


void agregarAlumno (void *cursos, int codigo, char *nombre, 
                    char **cursosAlum, int cantCurAlum,
                    int *cantDatXCur, int *tamXCur)
{
    void **arrayCursos = (void **) cursos;
    void **reg;
    int indiceCur;
    int *listaCod;
    char **listaNomb;
    
    for (int i = 0; i < cantCurAlum; i++){
        indiceCur = buscarCurso(cursos, cursosAlum[i]);
        reg = (void **) arrayCursos[indiceCur];
        if (reg[2] == NULL || reg[3] == NULL){
            //Se inicializa las listas de codigos y nombres
            reg[2] = new int[INCREMENTO];
            listaCod = (int *) reg[2];
            listaCod[0] = -1;
            
            reg[3] = new char *[INCREMENTO];
            listaNomb = (char **) reg[3];
            listaNomb[0] = NULL;
            
            cantDatXCur[indiceCur] = 1;
            tamXCur[indiceCur] = INCREMENTO;
        }
        
        listaCod = (int *) reg[2];
        listaNomb = (char **) reg[3];
        
        if (cantDatXCur[indiceCur] == tamXCur[indiceCur]){ //Esta lleno la lista
            aumentarTamListas(cursos, indiceCur, cantDatXCur, tamXCur);
            arrayCursos = (void **) cursos;
            reg = (void **) arrayCursos[indiceCur];
            listaCod = (int *) reg[2];
            listaNomb = (char **) reg[3];
        }
        
        listaCod[cantDatXCur[indiceCur] - 1] = codigo;
        listaCod[cantDatXCur[indiceCur]] = -1;
        listaNomb[cantDatXCur[indiceCur] - 1] = nombre;
        listaNomb[cantDatXCur[indiceCur]] = NULL;
        cantDatXCur[indiceCur]++;
        delete[]cursosAlum[i];
    }
}


int buscarCurso (void *cursos, char *codigoABuscar)
{
    void **arrayCursos = (void **) cursos;
    void **reg;
    char *codigoCur;
    
    int ind;
    for (ind = 0; arrayCursos[ind]; ind++){
        reg = (void **) arrayCursos[ind];
        codigoCur = (char *) reg[0];
        if (strcmp(codigoCur, codigoABuscar) == 0) break;
    }
    return ind;
}

void aumentarTamListas(void *cursos, int indiceCur,
                       int *cantDatXCur, int *tamXCur)
{
    void **arrayCursos = (void **) cursos;
    void **reg = (void **) arrayCursos[indiceCur];
    int *listaCod = (int *) reg[2];
    char **listaNomb = (char **) reg[3];
    int *listaCodAux;
    char **listaNombAux;
    
    tamXCur[indiceCur] += INCREMENTO;
    listaCodAux = new int[tamXCur[indiceCur]];
    listaNombAux = new char*[tamXCur[indiceCur]];
    
    for (int i = 0; i < cantDatXCur[indiceCur]; i++){
        listaCodAux[i] = listaCod[i];
        listaNombAux[i] = listaNomb[i];
    }
    delete[]listaCod;
    delete[]listaNomb;
    
    reg[2] = listaCodAux;
    reg[3] = listaNombAux;
}


void listaDeClase (void *cursos)
{
    void **arrayCursos = (void **) cursos;
    void **reg;
    char *codCur, *nombCur;
    char **listaNomb;
    int *listaCod;
    int cantAlum;
    
    
    printf("%50sListas de clases:\n"," ");
    
    for (int i = 0; arrayCursos[i]; i++){
        reg = (void **) arrayCursos[i];
        codCur = (char *) reg[0];
        nombCur = (char *) reg[1];
        listaCod = (int *) reg[2];
        listaNomb = (char **) reg[3];
        printNChar('=',140);
        for (cantAlum = 0; listaNomb[cantAlum]; cantAlum++ );
        printf("     Clave: %s                  Curso: %-40s", codCur, nombCur);
        printf("         Número de alumnos: %2d\n",cantAlum);
        printNChar('-',140);
        printf(" %-6s%-8s  %-40s   %-9s ","No.","Código","Nombre","Nota");
        printf("%-6s%-8s  %-40s   %-9s\n","No.","Código","Nombre","Nota");
        printNChar('-',140);
        int j;
        for (j = 0; listaNomb[j]; j++){
            if (j & 1)
                printf("%2d.-  %d  %-40s  %-10s\n",j+1,listaCod[j],listaNomb[j],"____");
            else
                printf("%2d.-  %d  %-40s  %-10s",j+1,listaCod[j],listaNomb[j],"____");
            
        }
        if (j & 1) putchar('\n');
    }
}



/*IMPRESION DE CADA FUNCION PEDIDA*/
void impCursos1 (void *cursos)
{
    void **array = (void **) cursos;
    for (int i = 0; array[i]; i++){
        void **reg = (void **) array[i];
        char *cod, *nomb;
        cod = (char *) reg[0];
        nomb = (char *) reg[1];
        printf("%s %s\n",cod, nomb);
    }
}

void printNChar(char c, int n, int ln)
{
  for (int i = 0; i < n; i++)
    putchar(c);
  if (ln) putchar('\n');
}