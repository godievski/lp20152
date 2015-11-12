/* 
 * File:   AdministradorDeArchivos.cpp
 * Author: alulab14
 * 
 * Created on 6 de noviembre de 2015, 08:07 AM
 */

/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#include "AdministradorDeArchivos.h"

AdministradorDeArchivos::AdministradorDeArchivos()
{
    nombreTxt[0] = nombreBin[0] = 0;
    
}

AdministradorDeArchivos::AdministradorDeArchivos(char *n)
{
    setNombres(n);
}

void AdministradorDeArchivos::crearArchivo (void)
{    
    if (!nombreTxt){
        cerr << "Nombre del archivo no válido.\n";
        exit(1);
    }
    
    ifstream archTxt (nombreTxt, ios::in);
    if (!archTxt){
        cerr << "No se pudo abrir el archivo <" << nombreTxt << ">.\n";
        exit(1);
    }
    
    ofstream archBin (nombreBin, ios::out | ios::binary);
    if (!archBin){
        cerr << "No se pudo abrir/crear el archivo <" << nombreBin << ">.\n";
        exit(1);
    }
    
    int codigo;
    char nombre[50];
    char especialidad[50];

    while (archTxt >> codigo){
        archTxt.get(); //Lee el espacio entre el codigo y nombre
        leeNombre(archTxt, nombre);
        leeEspecialidad(archTxt, especialidad);
        alum.SetCodigo(codigo);
        alum.SetEspecialidad(especialidad);
        alum.SetNombre(nombre);
        archBin.write(reinterpret_cast <const char*> (&alum), sizeof(alum));
    }
}

void AdministradorDeArchivos::leeNombre (ifstream &archTxt,char *nombre)
{
    int n = 0;
    char c;
    //Lee el espacio entre el codigo y nombre
    while (1){
        c = archTxt.get();
        if (c != ' ') break;
    }
    nombre[n] = c;
    n++;
    
    while (1){
        c = archTxt.get();
        if (c == '/') break;
        nombre[n] = c;
        n++;
    }
    int i = n - 1;
    while (nombre[i] == ' ') i--;
    nombre[i+1] = 0;
}

void AdministradorDeArchivos::leeEspecialidad (ifstream &archTxt,char *especialidad)
{
    int n = 0;
    char c;
    //Lee el espacio entre la barra y la especialidad
    while (1){
        c = archTxt.get();
        if (c != ' ') break;
    }
    especialidad[n] = c;
    n++;
    
    while (1){
        c = archTxt.get();
        if (c == '\n') break;
        especialidad[n] = c;
        n++;
    }
    especialidad[n] = 0;
}

void AdministradorDeArchivos::motrarArchivo (void)
{
    int tamArch;
    int cantReg;
    
    if (!nombreBin){
        cerr << "Nombre del archivo no válido.\n";
        exit(1);
    }
    
    ifstream archBin (nombreBin, ios::in | ios::binary);
    if (!archBin){
        cerr << "No se pudo abrir el archivo.\n";
        exit(1);
    }
    
    archBin.seekg(0,ios::end);
    tamArch = archBin.tellg();
    cantReg = tamArch / sizeof(alum);
    
    archBin.seekg(0,ios::beg);

    for (int i=0; i < cantReg; i++){
        archBin.read(reinterpret_cast<char *> (&alum), sizeof(alum));
        char nombre[50];
        char especialidad[50];
        alum.GetNombre(nombre);
        alum.GetEspecialidad(especialidad);
        cout << alum.GetCodigo() << " " << nombre << " " << especialidad << endl;
    }
}

void AdministradorDeArchivos::setNombres(char *nomb)
{
    /*Coloca el nombre al archivo de entrada y el de salida*/
    setNombreTxt(nomb);
    setNombreBin(nomb);
    int n = 0;
    
    while (nombreBin[n] != '.' && nombreBin[n]) n++;
    if (!nombreBin[n]){
        cerr << "El nombre del archivo\"" << nomb << "\" no tiene una extensión.\n";
        exit(1);
    }
    //Se cambia la extension a .bin el nombre el archivo
    nombreBin[n+1] = 'b';
    nombreBin[n+2] = 'i';
    nombreBin[n+3] = 'n';
    nombreBin[n+4] = 0;
    
}

void AdministradorDeArchivos::setNombreTxt(char* n) {
    strcpy(nombreTxt, n);
}

void AdministradorDeArchivos::getNombreTxt(char *n) const {
    strcpy(n, nombreTxt);
}

void AdministradorDeArchivos::setNombreBin(char* n) {
    strcpy(nombreBin, n);
}

void AdministradorDeArchivos::getNombreBin(char *n) const {
    strcpy(n, nombreBin);
}
