#include <iostream>
#include "Maze.hpp"

using namespace std;

int main(){
    Maze lab;
    int qntMatrix = lab.getNumberMatrix("dataset/input.data");
    for(int i = 1; i <= qntMatrix; i++){
        lab.start("dataset/input.data", i);
         auto start = std::chrono::high_resolution_clock::now();
        lab.randomMaze("dataset/matriz"+ to_string(i) +".data");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        double seconds = duration.count();
        std::cout << "(Aleatorio) Tempo decorrido da matriz : "<< i <<":" << seconds << " segundos." << std::endl;


        lab.createOutput("dataset/output_matriz"+ to_string(i) +".data", true);
        lab.start("dataset/input.data", i);
         start = std::chrono::high_resolution_clock::now();
        lab.depthFirstSearch("dataset/matriz"+ to_string(i) +".data");
         end = std::chrono::high_resolution_clock::now();
        duration = end - start;
         seconds = duration.count();
        std::cout << "(DFS) Tempo decorrido da matriz : "<< i <<":" << seconds << " segundos." << std::endl;


        lab.createOutput("dataset/output_matriz"+ to_string(i) +".data", false);
        lab.start("dataset/input.data", i);
        start = std::chrono::high_resolution_clock::now();
        lab.breadhtFirstSearch("dataset/matriz"+ to_string(i) +".data");
         end = std::chrono::high_resolution_clock::now();
        duration = end - start;
         seconds = duration.count();
        std::cout << "(BFS) Tempo decorrido da matriz : "<< i <<":" << seconds << " segundos." << std::endl;
        lab.createOutput("dataset/output_matriz"+ to_string(i) +".data", false);
        remove(("dataset/matriz"+ to_string(i) +".data").c_str());
        cout << endl;
    }
}