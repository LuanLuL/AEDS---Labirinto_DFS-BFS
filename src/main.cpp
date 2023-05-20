#include <iostream>
#include "Maze.hpp"

using namespace std;

int main(){
    Maze lab;
    int qntMatrix = lab.getNumberMatrix("dataset/input.data");
    for(int i = 1; i <= qntMatrix; i++){
        lab.start("dataset/input.data", i);
        lab.randomMaze("dataset/matriz"+ to_string(i) +".data");
        lab.createOutput("dataset/output_matriz"+ to_string(i) +".data", true);
        lab.start("dataset/input.data", i);
        lab.depthFirstSearch("dataset/matriz"+ to_string(i) +".data");
        lab.createOutput("dataset/output_matriz"+ to_string(i) +".data", false);
        lab.start("dataset/input.data", i);
        lab.breadhtFirstSearch("dataset/matriz"+ to_string(i) +".data");
        lab.createOutput("dataset/output_matriz"+ to_string(i) +".data", false);
        remove(("dataset/matriz"+ to_string(i) +".data").c_str());
    }
}