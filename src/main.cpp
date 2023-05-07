#include <iostream>
#include "Maze.hpp"
using namespace std;

int main(){
    Maze lab;
    int qntMatrix = lab.start("dataset/input.data");
    cout << qntMatrix;
}