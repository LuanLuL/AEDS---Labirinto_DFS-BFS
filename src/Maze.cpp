#include "Maze.hpp"

/******************************************************************************************** INICIO CONSTRUTORES */
Maze::Maze(){
    this->tamanhoLinha = 0;
    this->tamanhoColuna = 0;
    this->linha = 1;
    this->coluna = 1;
}

Maze::Maze(short int numeroLinha, short int numeroColuna){
    this->tamanhoLinha = numeroLinha;
    this->tamanhoColuna = numeroColuna;
    this->matriz = (short int**) calloc(this->tamanhoLinha, sizeof(short int*));
    for(int i=0;i<this->tamanhoLinha;i++){
        this->matriz[i] = (short int*) calloc(this->tamanhoColuna, sizeof(short int));
    }
    makeEdge();
    this->linha = 1;
    this->coluna = 1;
}
/******************************************************************************************** FINAL CONSTRUTORES */

/******************************************************************************************** INICIO GETTERS AND SETTERS */
short int  **Maze::getMatriz(){
    return this->matriz;
}

void Maze::setMatriz(short int  **newMatriz){
    this->matriz = newMatriz;
}

short int Maze::getTamanhoLinha(){
    return this->tamanhoLinha;
}

short int Maze::getTamanhoColuna(){
    return this->tamanhoColuna;
}

void Maze::setTamanho(short int newTamanhoLinha, short int newTamanhoColuna){
    this->tamanhoLinha = newTamanhoLinha;
    this->tamanhoColuna = newTamanhoColuna;
    this->matriz = (short int**) calloc(this->tamanhoLinha, sizeof(short int*));
    for(int i=0;i<this->tamanhoLinha;i++){
        this->matriz[i] = (short int*) calloc(this->tamanhoColuna, sizeof(short int));
    }
    makeEdge();
    this->linha = 1;
    this->coluna = 1;
}

short int Maze::getLinha(){
    return this->linha;
}

void Maze::setLinha(short int newLinha){
    this->linha = newLinha;
}

short int Maze::getColuna(){
    return this->coluna;
}

void Maze::setColuna(short int newColuna){
    this->coluna = newColuna;
}

Fila Maze::getFila(){
    return this->fila;
}

void Maze::setFila(Fila newFila){
    this->fila = newFila;
}

Pilha Maze::getPilha(){
    return this->pilha;
}

void Maze::setPilha(Pilha newPilha){
    this->pilha = newPilha;
}
/******************************************************************************************** FINAL GETTERS AND SETTERS */

/******************************************************************************************** INICIO METODOS */
void Maze::addNumber(short int number){
    try{
        if(this->linha == this->tamanhoLinha && this->coluna == this->tamanhoColuna){
			throw "../Matriz.cpp::addNumberMatriz ---> Matriz cheia";
		}
        this->matriz[this->linha][this->coluna] = number;
        if(this->coluna == this->tamanhoColuna-2){
            this->linha++;
            this->coluna = 1;
        }
        else if(this->coluna != this->tamanhoColuna-2){
            this->coluna++;
        }
    }
    catch(const char *msg){
        cerr << "\n\nERRO...ERRO " << msg << " ...ERRO...ERRO\n\n";
    }
}

void Maze::addNumberSelect(short int number){
    try{
        if(this->linha == this->tamanhoLinha && this->coluna == this->tamanhoColuna){
			throw "../Matriz.cpp::addNumberMatriz ---> Matriz cheia";
		}
        this->matriz[this->linha][this->coluna] = number;
        if(this->coluna == this->tamanhoColuna-1){
            this->linha++;
            this->coluna = 0;
        }
        else if(this->coluna != this->tamanhoColuna-1){
            this->coluna++;
        }
    }
    catch(const char *msg){
        cerr << "\n\nERRO...ERRO " << msg << " ...ERRO...ERRO\n\n";
    }
}

int Maze::start(string data){
    try{
        fstream inFile;
        inFile.open(data.c_str());
        if(!inFile){
            throw "../Maze::start(string data) ---> Não foi possível abrir o arquivo de entrada";
        }
        string numberStr;
        int aux = 0, aux2 = 0, numberInt = 0, limite = 0, i = 1, numMatrizes = 0;
        while (!inFile.eof()){
            if(aux == 0){
                getline(inFile, numberStr);
                if(aux2 == 0){
                    this->tamanhoLinha = atoi(&numberStr.at(0)) + 2;
                    this->tamanhoColuna = atoi(&numberStr.at(2)) + 2;
                    setTamanho(this->tamanhoLinha, this->tamanhoColuna);
                    numMatrizes = atoi(&numberStr.at(4));
                    aux2 = aux2 + 1;
                }
                aux = aux + 1;
            }
            else{
                inFile >> numberStr;
                if(numberStr == "*"){
                    numberInt = -1;
                }
                else if(numberStr == "#"){
                    numberInt = -2;
                }
                else if(numberStr == "?"){
                    numberInt = -3;
                }
                else{
                    numberInt = atoi(numberStr.c_str());
                }
                addNumber(numberInt);
                limite++;
                if(limite == ((this->tamanhoLinha-2) * (this->tamanhoColuna-2))){
                    aux = 0;
                    limite = 0;
                    create("dataset/matriz" + to_string(i) + ".data");
                    this->linha = 1;
                    this->coluna = 1;
                    i++;
                }
            }
        }
        inFile.close();
        return numMatrizes;
    }
    catch(const char *msg){
        cerr << "\n\n" << msg << "\n\n";
        exit(0);
    }
}

void Maze::makeEdge(){
    for(short int row = 0; row<this->tamanhoLinha; row++){
        for(short int column = 0; column<this->tamanhoColuna; column++){
            this->matriz[row][column] = -2;
        }
    }
}

void Maze::create(string name){
    try{
        ofstream outFile (name.c_str()); 
        if(!outFile){
            throw "../Maze::create(string name) ----> Não foi possível abrir o arquivo de saída";
        }
        outFile << this->tamanhoLinha << " " << this->tamanhoColuna << endl;
        this->matriz[1][1] = 1;
        for(int row = 0; row < this->tamanhoLinha; row++){
            for(int column = 0; column < this->tamanhoColuna; column++){
                outFile << this->matriz[row][column] << "\t";
            }
            outFile << endl;
        }
        outFile.close();
    }
    catch(const char *msg){
        cerr << "\n\n" << msg << "\n\n";
        exit(0);
    }
}

void Maze::print(){
    cout << endl;
    for(int i=0;i<this->tamanhoLinha;i++){
        for(int j=0;j<this->tamanhoColuna;j++){
            cout << this->matriz[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Maze::select(string data){
    fstream inFile;
        inFile.open(data.c_str());
        if(!inFile){
            throw "../Maze::select(string data) ---> Não foi possível abrir o arquivo de entrada";
        }
        string numberStr;
        int aux = 0, aux2 = 0, numberInt = 0, limite = 0;
        while (!inFile.eof()){
            if(aux == 0){
                getline(inFile, numberStr);
                if(aux2 == 0){
                    this->tamanhoLinha = atoi(&numberStr.at(0));
                    this->tamanhoColuna = atoi(&numberStr.at(2));
                    setTamanho(this->tamanhoLinha, this->tamanhoColuna);
                    aux2 = aux2 + 1;
                    this->linha = 0;
                    this->coluna = 0;
                }
                aux = aux + 1;
            }
            else{
                inFile >> numberStr;
                numberInt = atoi(numberStr.c_str());
                addNumberSelect(numberInt);
                limite++;
                if(limite == ((this->tamanhoLinha) * (this->tamanhoColuna))){
                    break;
                }
            }
        }
        inFile.close();
}

void Maze::breadhtFirstSearch(string data){
    short int i = 1, j = 1;
    on = true;
    this->fila.insert(i, j);
    while(this->on){  
        if(this->matriz[i][j] == -1){
            select(data);
            this->matriz[i][j] = 1;
            create(data);
            i = 1;
            j = 1;
            this->fila.clear();
            this->fila.insert(i, j);
            this->fila.print();
        }
        checkNextPathBFS(i+1, j);          // BAIXO
        checkNextPathBFS(i+1, j+1);        // DIAGONAL INFERIOR DIREITA
        checkNextPathBFS(i, j+1);          // DIREITA
        checkNextPathBFS(i-1, j+1);        // DIAGONAL SUPERIOR DIREITA
        checkNextPathBFS(i-1, j);          // CIMA         
        checkNextPathBFS(i-1, j-1);        // DIAGONAL SUPERIOR ESQUERDA         
        checkNextPathBFS(i, j-1);          // ESQUERDA         
        checkNextPathBFS(i+1, j-1);        // DIAGONAL INFERIOR ESQUERDA        
        this->fila.remove();
        this->fila.print(); 
        this->matriz[i][j] = 0;
        i = this->fila.getStart()->getI();
        j = this->fila.getStart()->getJ();
        print();
    }
}

void Maze::checkNextPathBFS(short int row, short int column){
    if(this->matriz[row][column] == 1){
        this->fila.insert(row, column);
        this->fila.print();
        this->matriz[row][column] = -4;
    }else if(this->matriz[row][column] == -1){
        this->fila.insert(row, column);
        this->fila.print();
    }
    else if(this->matriz[row][column] == -3){
        this->on = false;
    }
}

void Maze::depthFirstSearch(string data){
    short int i = 1, j = 1;
    this->on = true;
    this->pilha.push(i, j);
    this->matriz[i][j] = 0;
    print();
    while(this->on){
       if(this->matriz[i+1][j] == 1 || this->matriz[i+1][j] == -3 || this->matriz[i+1][j] == -1){       // BAIXO
            while(checkNextPathDFS(i+1,j, &i, &j, data)){
                i++;
                this->matriz[i][j] = 0;
                this->pilha.push(i, j);
                this->pilha.print();
                print();
            }
       }else if(this->matriz[i+1][j+1] == 1 || this->matriz[i+1][j+1] == -3 || this->matriz[i+1][j+1] == -1){       // DIAGONAL DIREITA INFERIOR
            while(checkNextPathDFS(i+1,j+1, &i, &j, data)){
                i++;
                j++;
                this->matriz[i][j] = 0;
                this->pilha.push(i, j);
                this->pilha.print();
                print();
            }
       }else if(this->matriz[i][j+1] == 1 || this->matriz[i][j+1] == -3 || this->matriz[i][j+1] == -1){       // DIREITA
            while(checkNextPathDFS(i,j+1, &i, &j, data)){
                j++;
                this->matriz[i][j] = 0;
                this->pilha.push(i, j);
                this->pilha.print();
                print();
            }
       }else if(this->matriz[i-1][j+1] == 1 || this->matriz[i-1][j+1] == -3 || this->matriz[i-1][j+1] == -1){       // DIAGONAL SUPERIOR DIREITA 
            while(checkNextPathDFS(i-1,j+1, &i, &j, data)){
                i--;
                j++;
                this->matriz[i][j] = 0;
                this->pilha.push(i, j);
                this->pilha.print();
                print();
            }
       }else if(this->matriz[i-1][j] == 1 || this->matriz[i-1][j] == -3 || this->matriz[i-1][j] == -1){       // CIMA
            while(checkNextPathDFS(i-1,j, &i, &j, data)){
                i--;
                this->matriz[i][j] = 0;
                this->pilha.push(i, j);
                this->pilha.print();
                print();
            }
       }else if(this->matriz[i-1][j-1] == 1 || this->matriz[i-1][j-1] == -3 || this->matriz[i-1][j-1] == -1){       // DIAGONA SUPERIOR ESQUERDA 
            while(checkNextPathDFS(i-1,j-1, &i, &j, data)){
                i--;
                j--;
                this->matriz[i][j] = 0;
                this->pilha.push(i, j);
                this->pilha.print();
                print();
            }
       }else if(this->matriz[i][j-1] == 1 || this->matriz[i][j-1] == -3 || this->matriz[i][j-1] == -1){       // ESQUERDA
            while(checkNextPathDFS(i,j-1, &i, &j, data)){
                j--;
                this->matriz[i][j] = 0;
                this->pilha.push(i, j);
                this->pilha.print();
                print();
            }
       }else if(this->matriz[i+1][j-1] == 1 || this->matriz[i+1][j-1] == -3 || this->matriz[i+1][j-1] == -1){       // DIAGONAL ESQUERDA INFERIOR
            while(checkNextPathDFS(i+1,j-1, &i, &j, data)){
                i++;
                j--;
                this->matriz[i][j] = 0;
                this->pilha.push(i, j);
                this->pilha.print();
                print();
            }
       }else{
        this->pilha.pop();
        this->pilha.print();
        this->matriz[i][j] = -4;
        print();
        i = this->pilha.getTopo()->getI();
        j = this->pilha.getTopo()->getJ();
       }
    }
}

bool Maze::checkNextPathDFS(short int row, short int column, short int *iP, short int *jP, string data){
    if(this->matriz[row][column] == 1){
        return true;
    } 
    else if(this->matriz[row][column] == -1){
        select(data);
        this->matriz[row][column] = 1;
        create(data);
        *iP = 1;
        *jP = 1;
        this->pilha.clear();
        this->pilha.push(*iP, *jP);
        this->pilha.print();
        this->matriz[*iP][*jP] = 0;
        print();
    }
    else if(this->matriz[row][column] == -3){
        this->on = false;
    }
    return false;
}
/******************************************************************************************** FINAL METODOS */