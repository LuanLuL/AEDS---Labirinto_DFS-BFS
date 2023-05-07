#include "No.hpp"


No::No(){
    this->i = 0;
    this->j = 0;
    this->next = NULL;
}

No::No(short int newI, short int newJ){
    this->i = newI;
    this->j = newJ;
    this->next = NULL;
}
/******************************************************************************************** FINAL CONSTRUTORES */

/******************************************************************************************** INICIO GETTERS AND SETTERS */
short int No::getI(){
    return this->i;
}

void No::setI(short int newI){
    this->i = newI;
}

short int No::getJ(){
    return this->j;
}

void No::setJ(short int newJ){
    this->j = newJ;
}

No *No::getNext(){
    return this->next;
}

void No::setNext(No *newNext){
    this->next = newNext;
}
/******************************************************************************************** FINAL GETTERS AND SETTERS */

/******************************************************************************************** INICIO METODOS */
void No::print(){
    cout << this->i << " " << this->j << endl;
}
/******************************************************************************************** FINAL METODOS */
