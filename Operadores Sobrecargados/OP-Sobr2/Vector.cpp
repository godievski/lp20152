#include "Vector.h"

Vector::Vector(float cx, float cy){
    x=cx;   y=cy;
}

void Vector::setX(float cx){
    x=cx;
}

void Vector::setY(float cy){
    y=cy;
}

float Vector::getX(void){
    return x;
}

float Vector::getY(void){
    return y;
}

float Vector::operator * (Vector v){
    return (x*v.x + y*v.y);
}

void Vector::operator * (float f){
    x*=f;        y*=f;
}

