/* 
 * File:   Evento.h
 * Author: Usuario
 *
 * Created on 30 de noviembre de 2015, 09:55 AM
 */

#ifndef EVENTO_H
#define	EVENTO_H

class Evento {
public:
    Evento();
    Evento(char*,int,int,char*);
    void SetAula(char* aula);
    void GetAula(char* aula) const;
    void SetHoraFin(int horaFin);
    int GetHoraFin() const;
    void SetHoraIni(int horaIni);
    int GetHoraIni() const;
    void SetDia(char* dia);
    void GetDia(char* dia) const;
    bool operator < (Evento&);
    int convertDia(void);
private:
    char dia[4];
    int horaIni;
    int horaFin;
    char aula[6];
};

#endif	/* EVENTO_H */

