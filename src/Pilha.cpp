#include "Pilha.hpp"

/******************************************************************************************** INICIO CONSTRUTORES */
Pilha::Pilha(){
    this->topo = NULL;
    this->base = this->topo;
}

Pilha::~Pilha(){
    while (!isEmpty()) {
        pop();
    }
}
/******************************************************************************************** FINAL CONSTRUTORES */

/******************************************************************************************** INICIO GETTERS AND SETTERS */
No *Pilha::getTopo(){
    return this->topo;
}

void Pilha::setTopo(No *newTopo){
    this->topo = newTopo;
}

No *Pilha::getBase(){
    return this->base;
}

void Pilha::setBase(No *newBase){
    this->topo = newBase;
}
/******************************************************************************************** FINAL GETTERS AND SETTERS */

/******************************************************************************************** INICIO METODOS */

void Pilha::push(short int newI, short int newJ) {
    try{
        No* novoNo = new No(newI, newJ);
        if(novoNo){
            if(isEmpty()){
                this->topo = novoNo; 
            }
            else{
                novoNo->setNext(this->topo);
                this->topo = novoNo;
            }
        }
        else{
            throw "../Pilha::push(short int valor) ---> Erro ao alocar memória!";
        }
    }
    catch(const char *msg){
        cerr << "\n\n" << msg << "\n\n";
        exit(0);
    }
}


void Pilha::pop() {
    if (isEmpty()) {
        cout << "A pilha está vazia.";
        return;
    }
    No* atual = topo;
    topo = topo->getNext();
    delete atual;
}


bool Pilha::isEmpty(){
    return (topo == NULL);
}

int Pilha::size(){
    int count = 0;
    No* atual = topo;
    while (atual != nullptr) {
        count++;
        atual = atual->getNext();
    }
    return count;
}

void Pilha::print(){
    No* aux = this->topo;
    if(isEmpty()){
        cout << "-----> PILHA VAZIA!";
    }
    else{
        cout << "\n\n";
        while(aux != NULL){
            aux->print();
            aux = aux->getNext();
        }
    }
}
/******************************************************************************************** FINAL METODOS */
