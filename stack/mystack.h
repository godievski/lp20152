/* 
 * File:   mystack.h
 * Author: Usuario
 *
 * Created on 30 de septiembre de 2015, 08:26 AM
 */

#ifndef MYSTACK_H
#define	MYSTACK_H

template <typename T>
void stack_create (T *&);

template <typename T>
void stack_push (T *&, T);

template <typename T>
T stack_pop (T *);

template <typename T>
bool stack_isEmpty (T *);

template <typename T>
int stack_size (T *);



#endif	/* MYSTACK_H */

