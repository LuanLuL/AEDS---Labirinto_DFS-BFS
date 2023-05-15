#include <iostream>
#include "Maze.hpp"


using namespace std;

int main(){
    // int cont = 10, i = 1, j = 1;
    // pair<int, int> par(0,0);

    // for(int k=0; k<cont; k++){
    //     lab.randomPath(i,j);
    //     i = par.first;
    //     j = par.second;
    //     cout<< i;
    //     cout<< j<< endl;

    //     cont--;
    // }
    Maze lab;
    int qntMatrix = lab.start("dataset/input.data");
    for(int i = 1; i <= qntMatrix; i++){
        lab.select("dataset/matriz"+ to_string(i) +".data");
        lab.breadhtFirstSearch("dataset/matriz"+ to_string(i) +".data");
        lab.print();
        break;
    }
}