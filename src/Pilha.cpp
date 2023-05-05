#include "Pilha.hpp"

/******************************************************************************************** INICIO CONSTRUTORES */
Pilha::Pilha(){
    topo = nullptr;
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
/******************************************************************************************** FINAL GETTERS AND SETTERS */

/******************************************************************************************** INICIO METODOS */

void Pilha::push(short int valor) {
    No* novoNo = new No;
    novoNo->setValue(valor);

    novoNo->setNext(topo);

    topo = novoNo;
}

void Pilha::pop() {
    if (isEmpty()) {
        std::cout << "A pilha está vazia." << std::endl;
        return;
    }

    No* atual = topo;
    topo = topo->getNext();
    delete atual;
}



bool Pilha::isEmpty(){
    return topo == nullptr;
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
/******************************************************************************************** FINAL METODOS */
