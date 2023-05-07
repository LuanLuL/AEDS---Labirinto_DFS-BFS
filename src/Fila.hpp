#ifndef __FILA_HPP
#define __FILA_HPP

#include <iostream>
#include "No.hpp"
using namespace std;

class Fila{
    private:
        No  *start;
        No *end;
    public:
        /************************************************** INICIO CONSTRUTORES */
        Fila();
        /************************************************** FINAL CONSTRUTORES */

        /************************************************** INICIO GETTERS AND SETTERS */
        No *getStart();
        void setStart(No *newStart);
        No *getEnd();
        void setEnd(No *newEnd);

        /************************************************** FINAL GETTERS AND SETTERS */
        
        /************************************************** INICIO METODOS */
        bool isEmpty();
        void insert(short int newI, short int newJ);
        void remove();
        void print();
        void clear();
        /************************************************** FINAL METODOS */

};

#endif