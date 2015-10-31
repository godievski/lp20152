/*SOLO LECTURA E IMPRESION*/
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include "mylib.h"
#include "myfunc.h"
#include "mytest.h"


/*CONSTANTES*/
#define MAX_BUFFER 1000
#define INCREMENTO 5
#define MAX_PALABRAS 200
#define MAX_NOMBRE 100

void leeDatos (void *&medicos, void *&pacientes)
{
    char trash[MAX_BUFFER];
    char *nombre;
    double *sueldo;
    int cant;
    int tam;
   
    /*PARTE DE MEDICOS*/
    gets(trash);
    void **arrayMed = new void*[INCREMENTO];
    tam = INCREMENTO;
    arrayMed[0] = NULL;
    cant = 1;
    medicos = arrayMed;
    while (1){
        if (leeMedico(nombre, sueldo) == NULL) break;
        agregarMedico(medicos, nombre, sueldo, tam, cant);
    }
    
    
    /*PARTE DE CONSULTAS*/
    tam = INCREMENTO;
    cant = 1;
    void *pacientesPorFecha;
    char *medico;
    void **arrayPac = new void*[INCREMENTO];
    arrayPac[0] = NULL;
    pacientes = arrayPac;
    while (1){
        if (leeConsulta(pacientesPorFecha, medico) == NULL) break;
        agregaPacYActualizaDatos(pacientes, medicos, pacientesPorFecha, medico, tam, cant);
    }
}

void * leeMedico(char *&nombre,double *&sueldo)
{
    char linea[MAX_BUFFER];
    char *palabras[MAX_PALABRAS];
    char buffNombre[MAX_NOMBRE];
    int cantPal;
    
    gets(linea);
    if (strcmp(linea, "Consultas:") == 0) return NULL;
    
    separarPalabras(linea, palabras, cantPal);
    
    strcpy(buffNombre, palabras[0]);
    strcat(buffNombre,"/");
    palabras[1][strlen(palabras[1]) - 1] = '\0';
    strcat(buffNombre, palabras[1]);
    strcat(buffNombre,"/");
    strcat(buffNombre,palabras[2]);
    
    for (int i = 3; i < cantPal - 2; i++){
        strcat(buffNombre,"-");
        strcat(buffNombre,palabras[i]);
    }
    nombre = new char[strlen(buffNombre) + 1];
    strcpy(nombre, buffNombre);
    sueldo = new double;
    *sueldo = atof(palabras[cantPal - 2]);
}

void agregarMedico(void *&medicos, char *nombre, double *sueldo, int &tam, int &cant)
{
    void **reg;
    void **arrayMed;
    int *cantPac = new int;
    *cantPac = 0;
    
    if (cant == tam)
        aumentarTam(medicos, tam, cant);
    arrayMed = (void **) medicos;
    arrayMed[cant-1] = new void*[3];
    reg = (void **) arrayMed[cant-1];
    reg[0] = nombre;
    reg[1] = sueldo;
    reg[2] = cantPac;
    arrayMed[cant] = NULL;
    cant++;    
}

void * leeConsulta(void *&pacientesPorFecha, char *&medico)
{
    char linea[MAX_BUFFER];
    char *palabras[MAX_PALABRAS];
    int cantPal;
    char bufferNomb[MAX_NOMBRE];
    char *nombre;
    char *bufferPac[MAX_BUFFER];
    
    if (gets(linea) == NULL) return NULL;
    
    separarPalabras(linea, palabras, cantPal);
    
    palabras[1][strlen(palabras[1]) - 1] = '\0';
    medico = palabras[1];
    
    int cantPac = 0;
    for (int i = 2; i < cantPal; i+=2){
        strcpy(bufferNomb, palabras[i+1]);
        strcat(bufferNomb," ");
        strcat(bufferNomb, palabras[i]);
        nombre = new char[strlen(bufferNomb)+1];
        strcpy(nombre, bufferNomb);
        bufferPac[cantPac] = nombre;
        cantPac++;
    }
    bufferPac[cantPac] = NULL;
    
    char **arrayPac = new char*[cantPac+1];
    for (int i=0; i <= cantPac; i++)
        arrayPac[i] = bufferPac[i];
    pacientesPorFecha = arrayPac;
}

void agregaPacYActualizaDatos(void *&pacientes, void *medicos, 
                              void *pacientesPorFecha,
                              char *medico,int &tam, int &cant)
{
    int indiceMed, indicePac;
    void **arrayMed = (void **) medicos;
    void **arrayPac = (void **) pacientes;
    char **arrayPacFecha = (char **) pacientesPorFecha;
    void **regMed;
    void **regPac;
    
    indiceMed = buscarEnArray(medicos, medico);
    if (arrayMed[indiceMed] == NULL){
        //printf("NO ENCONTRE NADA\n");
        return;
    }
    regMed = (void **) arrayMed[indiceMed];
    for (int i = 0; arrayPacFecha[i]; i++ ){
        int *cantPac;
        double *gasto;
        double *sueldo;
        cantPac = (int *) regMed[2];
        (*cantPac)++; //Aumenta la cantidad de visitas que ha tenido
        sueldo = (double *) regMed[1];
        indicePac = buscarEnArray(pacientes, arrayPacFecha[i]);
        
        if (arrayPac[indicePac] != NULL){ //LO ENCONTRO
            regPac = (void **) arrayPac[indicePac];
            gasto = (double *) regPac[1];
            *(gasto) += *(sueldo);
        } else { //NO LO ENCONTRO
            if (tam == cant){
                aumentarTam (pacientes, tam, cant);
                arrayPac = (void **) pacientes;
            }
            regPac = new void*[2];
            char *nombre = new char[strlen(arrayPacFecha[i])+1];
            strcpy(nombre, arrayPacFecha[i]);
            regPac[0] = nombre;
            gasto = new double;
            *gasto = *(sueldo);
            regPac[1] = gasto;
            arrayPac[indicePac] = regPac;
            arrayPac[indicePac + 1] = NULL;
            cant++;
        }
        delete[](arrayPacFecha[i]);
    }
    delete[]arrayPacFecha;
}

void aumentarTam (void *&datos, int &tam, int cant)
{
    tam += INCREMENTO;
    void **array = new void*[tam];
    void **arrayDatos = (void **) datos;
    
    for (int i = 0; i < cant; i++)
        array[i] = arrayDatos[i];
    delete[]arrayDatos;
    datos = array;
}


void separarPalabras(char *linea, char **palabras, int &cantPal)
{
    cantPal = 0;
    if (!isblank(linea[0])){
        palabras[0] = linea;
        cantPal++;
    }
    
    for (int i = 1; linea[i]; i++){
        if (!isblank(linea[i]) && (isblank(linea[i-1]) || linea[i-1] == 0)){
            palabras[cantPal] = &linea[i];
            cantPal++;
        }
        
        if (!isblank(linea[i]) && isblank(linea[i+1])){
            linea[i+1] = 0;
            i++;
        }
    }
}


void impInforme (void *medicos, void *pacientes)
{
    void **arrayMed = (void **) medicos;
    void **arrayPac = (void **) pacientes;

    printf("PACIENTES\n");
    printf("===============================================\n");
    myQuickSort(pacientes);
    for (int i = 0; arrayPac[i]; i++){
        void **reg = (void **) arrayPac[i];
        char *nombre = (char*) reg[0];
        double *gastos = (double *) reg[1];
        printf("%03d) %-30s %10.2lf\n",i+1,nombre, *gastos);
    }
    
        
    printf("\nMEDICOS!!!\n");
    printf("===============================================\n");
    myQuickSort(medicos);
    for(int i = 0; arrayMed[i]; i++){
        void **reg = (void **) arrayMed[i];
        char *nombre = (char *) reg[0];
        double *sueldo = (double *) reg[1];
        int *cant = (int *) reg[2];
        printf("%02d) %-50s %10.2lf\n",i+1,nombre, (*sueldo) * (*cant));
    }
}


