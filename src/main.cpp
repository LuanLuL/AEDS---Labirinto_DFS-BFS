#include <iostream>
#include "Maze.hpp"


using namespace std;

int main(){
    Maze lab;
    int qntMatrix = lab.start("dataset/input.data");
    for(int i = 1; i <= qntMatrix; i++){
        lab.select("dataset/matriz"+ to_string(i) +".data");
        lab.randomMaze("dataset/matriz"+ to_string(i) +".data");
        lab.select("dataset/matriz"+ to_string(i) +".data");
        lab.breadhtFirstSearch("dataset/matriz"+ to_string(i) +".data");
        break;
    }
}