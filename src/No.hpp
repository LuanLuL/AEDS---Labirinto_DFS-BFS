#ifndef __NO_HPP
#define __NO_HPP

#include <iostream>
using namespace std;

class No{
    private:
        short int i, j;
        No *next;
    public:
        /************************************************** INICIO CONSTRUTORES */
        No();
        No(short int i, short int j);
        /************************************************** FINAL CONSTRUTORES */

        /************************************************** INICIO GETTERS AND SETTERS */
        short int getI();
        void setI(short int newI);
        short int getJ();
        void setJ(short int newJ);
        No *getNext();
        void setNext(No *newNext);
        /************************************************** FINAL GETTERS AND SETTERS */

        /************************************************** INICIO METODOS */
        void print();
        /************************************************** FINAL METODOS */
};

#endif
