#include "A.h"
#include "B.h"

B::B(void)
{ cant = 0;
}

void B::setB(int x){
    b = x;
}

int B::getB(void){
    return b;
}

int B::getCant(void){
    return cant;
}

void B::ingresa(int x){
    m[cant++].setA(x);
}
int B::operator[](int i){
    return m[i].getA();
}

int B::operator () (int p, int q){
    return cant*p + q;
}

