#ifndef __PILHA_HPP
#define __PILHA_HPP

#include<iostream>
#include<stdlib.h>
#include "No.hpp"

using namespace std;

class Pilha{
    private:
        No* topo;
        No* base;
    public:
        /************************************************** INICIO CONSTRUTORES */
        Pilha();
        ~Pilha();
        /************************************************** FINAL CONSTRUTORES */

        /************************************************** INICIO GETTERS AND SETTERS */
        No *getTopo();
        void setTopo(No *newTopo);
        No *getBase();
        void setBase(No *newBase);
        /************************************************** FINAL GETTERS AND SETTERS */

        /************************************************** INICIO METODOS */
        void push(short int newI, short int newJ);
        void pop();
        bool isEmpty();
        int size();
        void clear();
        void print();
        /************************************************** FINAL METODOS */
};

#endif
