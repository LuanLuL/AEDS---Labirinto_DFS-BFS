#ifndef __MAZE_HPP
#define __MAZE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include "Fila.hpp"
using namespace std;

class Maze{
    private:
        short int **matriz, linha, coluna, tamanhoLinha, tamanhoColuna;
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
        /*************************************************************** FINAL GETTERS AND SETTERS */

        /*************************************************************** INICIO METODOS */
        void addNumber(short int number);
        int start(string data);
        void makeEdge();
        void create(string data);
        void print();
        void select(string data);
        //int breadhtFirstSearch();
        /************************************************************** FINAL METODOS */
};

#endif


