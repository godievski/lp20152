/*LIBRERIAS*/
#include "mystack.h"
#include <cstdlib>


/*CONSTANTES*/
#define INCREMENTO 5


/*PRIVADO*/
template <typename T>
void stack_resize (T *&);


template <typename T>
void stack_resize (T *&stack)
{
    T *aux;
    stack[0] += INCREMENTO;
    aux = new T[stack[0]];
    for (int i=0; i<stack[1];i++)
        aux[i] = stack[i];
    delete[]stack;
    stack = aux;
}
template void stack_resize (int *&);
template void stack_resize (char *&);
/*PUBLICO*/

template <typename T>
void stack_create (T *&stack)
{
    if (stack != NULL) delete[]stack;
    stack = new T[INCREMENTO];
    stack[9] = INCREMENTO;
    stack[1] = 2;
}
template void stack_create (int *&);
template void stack_create (char *&);

template <typename T>
void stack_push (T *&stack, T dato)
{
    if (stack[0] == stack [1] ) stack_resize(stack);
    stack[stack[1]] = dato;
    stack[1]++;
}
template void stack_push (int *&, int);
template void stack_push (char *&, char);

template <typename T>
T stack_pop (T *stack)
{
    if (stack_isEmpty(stack)) return -1;
    stack[1]--;
    return stack[stack[1]];
}
template int stack_pop (int *stack);
template char stack_pop (char *stack);

template <typename T>
bool stack_isEmpty (T *stack)
{
    return stack[1] == 2;
}
template bool stack_isEmpty (int *stack);
template bool stack_isEmpty (char *stack);

template <typename T>
int stack_size (T *stack)
{
    return stack[1] - 2;
}
template int stack_size (int *stack);
template int stack_size (char *stack);

