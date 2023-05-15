#ifndef __MAZE_HPP
#define __MAZE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <tuple>
#include "Fila.hpp"
#include "Pilha.hpp"
using namespace std;

class Maze{
    private:
        short int **matriz, linha, coluna, tamanhoLinha, tamanhoColuna;
        Fila fila;
        Pilha pilha;
        bool on;

    public:
        /*************************************************************** INICIO CONSTRUTORES */
        Maze();
        Maze(short int numeroLinha, short int numeroColuna);
        /*************************************************************** FINAL CONSTRUTORES */

        /*************************************************************** INICIO GETTERS AND SETTERS */
        short int **getMatriz(); 
        void setMatriz(short int  **newMatriz);
        short int getTamanhoLinha();
        short int getTamanhoColuna();
        void setTamanho(short int newTamanhoLinha, short int newTamanhoColuna);
        short int getLinha();
        void setLinha(short int newLinha);
        short int getColuna();
        void setColuna(short int newColuna);
        Fila getFila();
        void setFila(Fila newFila);
        Pilha getPilha();
        void setPilha(Pilha newPilha);
        /*************************************************************** FINAL GETTERS AND SETTERS */

        /*************************************************************** INICIO METODOS */
        void addNumber(short int number);
        void addNumberSelect(short int number);
        int start(string data);
        void makeEdge();
        void create(string data);
        void print();
        void select(string data);
        void breadhtFirstSearch(string data);
        void checkNextPathBFS(short int row, short int column);
        bool checkNextPathDFS(short int row, short int column, short int *iP, short int *jP, string data);
        void depthFirstSearch(string data);
        pair<int, int> randomPath(int i, int j);
        /************************************************************** FINAL METODOS */
};

#endif