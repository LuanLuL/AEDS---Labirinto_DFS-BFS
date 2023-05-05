#ifndef __PILHA_HPP
#define __PILHA_HPP

#include<iostream>
#include<stdlib.h>
#include "No.hpp"

using namespace std;

class Pilha{
    private:
        No* topo;
    public:
        /************************************************** INICIO CONSTRUTORES */
        Pilha();
        ~Pilha();
        /************************************************** FINAL CONSTRUTORES */

        /************************************************** INICIO GETTERS AND SETTERS */
        No *getTopo();
        void setTopo(No *newTopo);
        /************************************************** FINAL GETTERS AND SETTERS */

        /************************************************** INICIO METODOS */
        void push(short int valor);
        void pop();
        bool isEmpty();
        int size();
        /************************************************** FINAL METODOS */
};

#endif
