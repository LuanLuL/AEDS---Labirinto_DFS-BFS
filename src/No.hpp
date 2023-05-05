#ifndef __NO_HPP
#define __NO_HPP

#include <iostream>
using namespace std;

class No{
    private:
        short int value;
        No *next;
    public:
        /************************************************** INICIO CONSTRUTORES */
        No();
        No(short int newValue);
        /************************************************** FINAL CONSTRUTORES */

        /************************************************** INICIO GETTERS AND SETTERS */
        short int getValue();
        void setValue(short int newValue);
        No *getNext();
        void setNext(No *newNext);
        /************************************************** FINAL GETTERS AND SETTERS */

        /************************************************** INICIO METODOS */
        void print();
        /************************************************** FINAL METODOS */
};

#endif
