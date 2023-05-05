#include "No.hpp"


No::No(){
    this->value = 0;
    this->next = NULL;
}

No::No(short int newValue){
    this->value = newValue;
    this->next = NULL;
}
/******************************************************************************************** FINAL CONSTRUTORES */

/******************************************************************************************** INICIO GETTERS AND SETTERS */
short int No::getValue(){
    return this->value;
}

void No::setValue(short int newValue){
    this->value = newValue;
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
    cout << this->value << endl;
}
/******************************************************************************************** FINAL METODOS */
