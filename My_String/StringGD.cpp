/* 
 * File:   StringGD.cpp
 * Author: Usuario
 * 
 * Created on 11 de noviembre de 2015, 10:06 AM
 */

#include "StringGD.h"

StringGD::StringGD ()
{
    str = NULL;
    len = cap = 0;
}

StringGD::StringGD (char *str)
{
    if (!str){
        cerr << "Paramater invalid.\n";
        exit(1);
    }
    cap = len = _strlen(str);
    int i = 0;
    this->str = new char[len];
    while (str[i]){
        this->str[i] = str[i];
        i++;
    }
}

StringGD::StringGD (int cap)
{
    if (cap <= 0){
        cerr << "The capacity must be a positive number.\n";
        exit(1);
    }
    this->cap = cap;
    this->str = new char[cap];
    this->len = 0;        
}

StringGD::StringGD (const StringGD& orig)
{
    cap = orig.cap;
    len = orig.len;
    str = new char[cap];
    for (int i = 0; i < len; i++)
        str[i] = orig.str[i];
}

StringGD::~StringGD () 
{
    delete [] str;
}

int StringGD::length (void) const
{
    return len;
}

void StringGD::assign (char* str)
{
    if (!str){
        cerr << "Error in assign method. Null is not permited\n";
        exit(1);
    }
    int len_str = _strlen(str);
    this->len = len_str;
    if (len_str > cap){
        cap = (INCREMENT + 1) * len_str;
        delete [] this->str;
        this->str = new char[cap];
    }
    for (int i = 0; i < len_str; i++)
        this->str[i] = str[i];
}

void StringGD::assign (const StringGD& orig)
{
    if (!(orig.str)){
        cerr << "Error in assign method. Null is not permited\n";
        exit(1);
    }
    this->len = orig.length();
    if (orig.length() > this->cap){
        this->cap = (INCREMENT + 1) * orig.length();
        delete [] this->str;
        this->str = new char[this->len];
    }
    for (int i = 0; i < this->len; i++)
        this->str[i] = orig.str[i];
}

StringGD& StringGD::operator = (char* str)
{
    if (!str){
        cerr << "Error in assignment operator. Null is not permited\n";
        exit(1);
    }
    assign(str);
    return *this;
}

StringGD& StringGD::operator = (const StringGD& orig)
{
    assign(orig);
    return *this;
}

void StringGD::append (char * str)
{
    if (!str){
        cerr << "Error in append method. Null is not permited\n";
        exit(1);
    }
    int len_str = _strlen(str);
    int lim = len + len_str;
    if (lim > cap){
        char *temp_self = new char[len+1];
        char_cast(temp_self);
        cap = (1 + INCREMENT) * lim;
        delete [] this->str;
        this->str = new char[cap];
        for (int i = 0; i < len; i++)
            (this->str)[i] = temp_self[i];
        delete [] temp_self;
    }
    for (int i = len; i < lim; i++)
        (this->str)[i] = str[i - len];
    len += len_str;
}

void StringGD::append (const StringGD& orig)
{   
    if (!orig.str){
        cerr << "Error in append method. Null is not permited\n";
        exit(1);
    }
    int len_str = orig.length();
    int lim = len + len_str;
    if (lim > cap){
        char *temp_self = new char[len+1];
        char_cast(temp_self);
        cap = (1 + INCREMENT) * lim;
        delete [] this->str;
        this->str = new char[cap];
        for (int i = 0; i < len; i++)
            (this->str)[i] = temp_self[i];
        delete [] temp_self;
    }
    for (int i = len; i < lim; i++)
        (this->str)[i] = orig.str[i - len];
    len += len_str;
}

void StringGD::swap (StringGD& orig)
{
    StringGD temp = orig;
    orig.assign(*this);
    assign(temp);
}

StringGD StringGD::operator + (const StringGD& orig) const
{
    StringGD temp_ob;
    temp_ob.assign(*this);
    temp_ob.append(orig);
    return StringGD (temp_ob);
}

int StringGD::compare (char *str) const
{
    int len_str = _strlen(str);
    int min_len;
    min_len = _min(len, len_str);
    for (int i = 0; i < min_len; i++){
        if (this->str[i] > str[i])
            return 1;
        else if (this->str[i] < str[i])
            return -1;
    }
    
    if (len == len_str)
        return 0;
    else if (min_len == len)
        return -1;
    else{
        return 1;
    }
}

int StringGD::compare (const StringGD& orig) const
{
    int orig_len = orig.length();
    int min_len;
    min_len = _min(len, orig_len);
    for (int i = 0; i < min_len; i++){
        if (this->str[i] > orig.str[i])
            return 1;
        else if (this->str[i] < orig.str[i])
            return -1;
    }
    if (len == orig_len)
        return 0;
    else if (min_len == len)
        return -1;
    else{
        return 1;
    }
}

int StringGD::operator == (const StringGD& orig) const
{
    return compare(orig) == 0;
}

int StringGD::operator < (const StringGD& orig) const
{
    return compare(orig) < 0;
}

int StringGD::operator > (const StringGD& orig) const
{
    return compare(orig) > 0;
}

void StringGD::print (void) const
{
    for (int i = 0; i < len; i++)
        cout << str[i];
}

void StringGD::char_cast(char * str) const
{
    if (!str){
        cerr << "Error in char_cast method. Null is not permited\n";
        exit(1);
    }
    int i;
    for (i = 0; i < len; i++)
        str[i] = this->str[i];
    str[len] = 0;
}

int StringGD::_strlen (char *str) const
{
    int len = 0;
    while (*str != '\0'){
        str++;
        len++;
    }
    return len;
}

int StringGD::_min (int len, int len_str) const
{
    if (len < len_str)
        return len;
    else
        return len_str;
}