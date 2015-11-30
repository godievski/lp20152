/* 
 * File:   Ficha.h
 * Author: Usuario
 *
 * Created on 28 de noviembre de 2015, 10:03 PM
 */

#ifndef FICHA_H
#define	FICHA_H

class Ficha {
public:
    virtual void mover (int, char);
    void setTipo(char tipo);
    char getTipo() const;
    void setColumna(int columna);
    int getColumna() const;
    void setFila(int fila);
    int getFila() const;
    void setId(char* id);
    void getId(char* id) const;
private:
    char id[10];
    int fila;
    int columna;
    char tipo;
};

#endif	/* FICHA_H */

