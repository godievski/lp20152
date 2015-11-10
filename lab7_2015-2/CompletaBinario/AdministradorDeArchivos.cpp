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

AdministradorDeArchivos::AdministradorDeArchivos(char *nombTxt, char *nombBin)
{
    setNombreTxt(nombTxt);
    setNombreBin(nombBin);
}

void AdministradorDeArchivos::actualizarArchivo (void)
{    
    if (!nombreTxt ||  !nombreBin){
        cerr << "Nombre del archivo no válido.\n";
        exit(1);
    }
    
    ifstream archTxt (nombreTxt, ios::in);
    if (!archTxt){
        cerr << "No se pudo abrir el archivo <" << nombreTxt << ">.\n";
        exit(1);
    }
    
    fstream archBin (nombreBin, ios::in | ios::out | ios::binary);
    if (!archBin){
        cerr << "No se pudo abrir el archivo <" << nombreBin << ">.\n";
        exit(1);
    }
    
    void *fin;
    int codigo;
    int anho, sem;
    char trash[30], codStr[30], linea[1000];
    
    archTxt.getline(trash,30,' ');
    while (1){
        archTxt >> anho >> sem;
        while (archTxt.get() != '\n');
        while (1){
            if (fin = archTxt.getline(codStr, 30, ' '))
                codigo = atoi(codStr);
            else
                codigo = 0;
            if (codigo == 0) break;
            archTxt.getline(linea,1000);
            actualizaDatos(archBin, codigo, anho, sem, linea);
        }
        if (!fin) break;
    }
    actualizaProm(archBin);
}

void AdministradorDeArchivos::actualizaDatos(fstream &archBin, int codigo,
                                int anho, int sem, char*linea)
{
    char* palabras[200];
    int pos = 0, cantPal=0;
    
    buscarAlumno(archBin, codigo, pos);
    //cout << "NO ERROR: BUSCARALUMNO \n";
    
    actualizaAnhoSemestre(anho, sem);
    //cout << "NO ERROR: ACTUALIZA_ANHO_SEMESTRE\n";
    
    separaPalabras(linea, palabras, cantPal);
    //cout << "NO ERROR: SEPARA_PALABRAS\n";
    
    actualizaNotasCred(palabras, cantPal);
    //cout << "NO ERROR: ACTUALIZA_NOTAS\n";

    
    /*SOBRE-ESCRIBE LOS DATOS DE UN ALUMNO EN LA POSICION CORRESPONDIENTE*/
    archBin.seekg(pos * sizeof(alum), ios::beg);
    archBin.write(reinterpret_cast <const char*> (&alum), sizeof(alum));
        
}

void AdministradorDeArchivos::buscarAlumno(fstream &archBin,int codigo,int &pos)
{
    int tamArch, cantReg;
    archBin.seekg(0,ios::end);
    tamArch = archBin.tellg();
    cantReg = tamArch / sizeof(alum);
    archBin.seekg(0,ios::beg);
    pos = 0;
    for (pos = 0; pos < cantReg; pos++){
        archBin.read(reinterpret_cast <char *> (&alum), sizeof(alum));
        if (alum.GetCodigo() == codigo) break;
    }
    if (pos >= cantReg){
        cerr << "Hubo un error. No se encontró el alumno\n";
        exit(1);
    }
}

void AdministradorDeArchivos::actualizaAnhoSemestre(int anho, int sem)
{
    if (alum.GetAnIn() == 0){
        alum.SetAnIn(anho);
        alum.SetSemIn(sem);
    } else {
        alum.SetAnFin(anho);
        alum.SetSemFin(sem);
    }
}

void AdministradorDeArchivos::separaPalabras(char *linea,
                            char **palabras, int &cantPal)
{   
    cantPal = 0;
    
    if (!isblank(linea[0])){
        palabras[0] = linea;
        cantPal++;
    }
    
    for (int i = 1; linea[i]; i++){
        if (!isblank(linea[i]) && (isblank(linea[i-1]) || linea[i-1] == 0)){
            palabras[cantPal] = &(linea[i]);
            cantPal++;
        }
        if (!isblank(linea[i]) && isblank(linea[i+1]) ){
            linea[i+1] = 0;
            i++;
        }
    }
}

void AdministradorDeArchivos::actualizaNotasCred(char **palabras, int cantPal)
{
    double cred;
    int nota;
    double prom;
    for (int i = 0; i < cantPal; i+=3){
        cred = atof(palabras[i+1]);
        if (cred == 0){
            cerr << "Error en el archivo de texto.\n";
            exit(1);
        }
        nota = atoi(palabras[i+2]);
        if (!nota){
            cerr << "Error en el archivo de texto.\n";
            exit(1);
        }
        prom = cred*nota;
        cred += alum.GetCreditos();
        prom += alum.GetPromedio();
        alum.SetCreditos(cred);
        alum.SetPromedio(prom);
    }
}


void AdministradorDeArchivos::actualizaProm(fstream &archBin)
{
    int tamArch, cantReg;
    double prom, cred;

    archBin.seekg(0, ios::end);
    tamArch = archBin.tellg();
    cantReg = tamArch / sizeof(alum);
    
    archBin.seekg(0, ios::beg);
    for (int i = 0; i < cantReg; i++){
        archBin.read(reinterpret_cast <char*> (&alum), sizeof(alum));
        prom = alum.GetPromedio();
        cred = alum.GetCreditos();
        if (cred != 0){
            prom = prom / cred;
            cerr << "ERROR: Division entre cero.\n";
            exit(1);
        }
        alum.SetPromedio(prom);
        archBin.seekg(i * sizeof(alum), ios::beg);
        archBin.write(reinterpret_cast <const char*> (&alum), sizeof(alum));
    }
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
        alum.mostrar();
    }
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
