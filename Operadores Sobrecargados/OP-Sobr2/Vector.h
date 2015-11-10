/* 
 * File:   Vector.h
 * Author: Miguel
 *
 * Created on 19 de junio de 2009, 09:17 PM
 */

#ifndef _VECTOR_H
#define	_VECTOR_H
class Vector {
    float x;
    float y;
public:
    Vector(float cx=0, float cy=0);
    void setX(float);
    void setY(float);
    float getX(void);
    float getY(void);
    float operator * (Vector); //producto escalar
    void operator * (float);   // un factor multiplicar  al vector
};
#endif	/* _VECTOR_H */

