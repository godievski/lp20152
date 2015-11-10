/* 
 * File:   Reloj.h
 * Author: Miguel Guanira
 *
 * Created on 17 de junio de 2009, 11:03 PM
 *
 * Ejemplo sencillo de operador unario sobrecargado (++  prefijo)
 * El operador incrementa en un segundo el reloj
 */

#ifndef _RELOJ_H
#define	_RELOJ_H
class Reloj{
    int hora;
    int minuto;
    int segundo;
public:
    Reloj(int h=0, int m=0, int s=0);
    void DefineTiempo(int, int, int);
    void DefineHora(int);
    void DefineMinuto(int);
    void DefineSegundo(int);
    int Hora(void);
    int Minuto(void);
    int Segundo(void);
    void operator ++ (void);
    //sobrecarga: incrementa en un seg. el reloj
 };
#endif	/* _RELOJ_H */

