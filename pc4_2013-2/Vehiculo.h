/* 
 * File:   Vehiculo.h
 * Author: Usuario
 *
 * Created on 19 de noviembre de 2015, 02:46 PM
 */

#ifndef VEHICULO_H
#define	VEHICULO_H



class Vehiculo {
public:
    Vehiculo();
    virtual ~Vehiculo();
    void SetNumAsientos(int numAsientos);
    int GetNumAsientos() const;
    void SetChofer(char* chofer);
    void GetChofer(char *chofer) const;
    void SetPlaca(char* placa);
    void GetPlaca(char* placa) const;
    void SetRuta(char** ruta, int cant);
    void impRuta (void);
protected:
    char** GetRuta (void);
    void GetRuta (char*, int);
private:
    char *placa;
    char *chofer;
    int numAsientos;
    char **ruta;
};

#endif	/* VEHICULO_H */

