/* 
 * File:   ClsCursos.h
 * Author: Usuario
 *
 * Created on 29 de octubre de 2015, 09:56 AM
 */

#ifndef CLSCURSOS_H
#define	CLSCURSOS_H

#include <fstream>
using namespace std;

class ClsCursos {
public:
    ClsCursos();
    ClsCursos(char* nombre, char* codigo, double creditos);
    ClsCursos(const ClsCursos& orig);
    virtual ~ClsCursos();
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetNombre(char* nombre);
    char* GetNombre(char* nombre) const;
    void SetCodigo(char* codigo);
    char* GetCodigo(char* codigo) const;
    void impDatos (ofstream &archOut);
private:
    char *codigo;
    char *nombre;
    double creditos;
};

#endif	/* CLSCURSOS_H */

