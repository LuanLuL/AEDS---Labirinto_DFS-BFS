#include "Fila.hpp"

/************************************************** INICIO CONSTRUTORES */
Fila::Fila(){
    this->start = NULL;
    this->end = NULL;
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

void Fila::insert(short int newI, short int newJ){
    try{
        No *newNo = new No(newI, newJ);
        if(newNo){
            if(isEmpty()){
                this->start = newNo;
                this->end = newNo;
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

void Fila::remove(){
    if(isEmpty()){
        cout << "\n---> A lista não possui elementos!";
    }
    else{
        No *aux = this->start;
        this->start = aux->getNext();
        delete aux;
    }
}

void Fila::print(){
    No *aux = this->start;
    cout << "---------- FILA ----------\n\n";
    if(isEmpty()){
        cout << "---> A lista não possui elementos!\n";
    }
    else{
        while (aux != NULL){
            aux->print();
            aux = aux->getNext();
        }
    }
    cout << "\n---------- FIM FILA ----------\n";
}
void Fila::clear(){
    if(isEmpty()){
        cout << "\n---> A lista não possui elementos!";
    }
    else{
        No *aux = this->start;
       while(aux != NULL){
            this->start = aux->getNext();
            No* aux2 = aux;
            aux = aux->getNext();
            delete aux2;
       }
    }
}
/******************************************************************************************** FINAL METODOS */
