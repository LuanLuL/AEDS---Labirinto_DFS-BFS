#include "Fila.hpp"

/************************************************** INICIO CONSTRUTORES */
Fila::Fila(){
    this->start = NULL;
    this->end = this->start;
}
/************************************************** FINAL CONSTRUTORES */

/************************************************** INICIO GETTERS AND SETTERS */
No *Fila::getStart(){
    return this->start;
}

void Fila::setStart(No *newStart){
    this->start = newStart;
}

No *Fila::getEnd(){
    return this->end;
}

void Fila::setEnd(No *newEnd){
    this->end = newEnd;
}
/************************************************** FINAL GETTERS AND SETTERS */

/******************************************************************************************** INICIO METODOS */
bool Fila::isEmpty(){
    return (this->start == NULL);
}

void Fila::insert(short int newValue){
    try{
        No *newNo = new No(newValue);
        if(newNo){
            newNo->setValue(newValue);
            newNo->setNext(NULL);
            if(isEmpty()){
                this->start = newNo;
                this->end = start;
            }
            else{
                this->end->setNext(newNo);
                this->end = newNo;
            }
        }
        else{
            throw "../Fila::insert(No **fila, short int newValue) ---> Erro ao alocar memória!";
        }
    }
    catch(const char *msg){
        cerr << "\n\n" << msg << "\n\n";
        exit(0);
    }
}

void Fila::print(){
    No *aux = this->start;
    if(isEmpty()){
        cout << "---> A lista não possui elementos!";
    }
    else{
        while (aux != NULL){
            aux->print();
            aux = aux->getNext();
        }
    }
}
/******************************************************************************************** FINAL METODOS */
