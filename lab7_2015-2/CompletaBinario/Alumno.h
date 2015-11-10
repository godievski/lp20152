/* 
 * File:   Alumno.h
 * Author: alulab14
 *
 * Created on 6 de noviembre de 2015, 08:03 AM
 */

/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#ifndef ALUMNO_H
#define	ALUMNO_H

#include <cstdlib>
#include <cstring>

class Alumno {
public:
    Alumno();
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetPromedio(double promedio);
    double GetPromedio() const;
    void SetSemFin(int semFin);
    int GetSemFin() const;
    void SetAnFin(int anFin);
    int GetAnFin() const;
    void SetSemIn(int semIn);
    int GetSemIn() const;
    void SetAnIn(int anIn);
    int GetAnIn() const;
    void SetNombre(char *);
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetEspecialidad(char *);
    void GetEspecialidad(char *) const;
    void mostrar(void) const;
private:
    int codigo;
    char nombre[50];
    char especialidad[50];
    int anIn; //Año de inicio
    int semIn; //Semestre que inicio
    int anFin; //Año de egresó
    int semFin; //Semestre que egresó
    double promedio;
    double creditos;
};

#endif	/* ALUMNO_H */

