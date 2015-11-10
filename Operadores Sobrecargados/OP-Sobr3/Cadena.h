/* 
 * File:   Cadena.h
 * Author: Miguel
 *
 * Created on 19 de junio de 2009, 09:39 PM
 */

#ifndef _CADENA_H
#define	_CADENA_H
class Cadena{
    char *cad;
public:
    void setCadena(char *);
    char * getCadena(void);
    void imprimeCad(void);
    void operator + (Cadena);
};
#endif	/* _CADENA_H */


