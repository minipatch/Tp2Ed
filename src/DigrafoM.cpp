#include "DigrafoM.hpp"

DigrafoM::DigrafoM(int numvertices){

    this->_numvertice = numvertices;

    // inicializando a matriz dinamicamente
    Matriz = new double*[_numvertice];

    for(int i=0;i<_numvertice;i++){
        Matriz[i] = new double[_numvertice];
    }
    
    // iniciliazando grafo com arestas inexistentes
    for(int i=0;i<_numvertice;i++){
        for(int j=0;j<_numvertice;j++){
            Matriz[i][j] = -1;
        }
    }

    p = new Ponto[_numvertice];
}


DigrafoM::~DigrafoM(){
    for(int i=0;i<_numvertice;i++){
        delete[] Matriz[i];
    }
    delete[] Matriz;
}

// adiciona os pontos nas arestas 
void DigrafoM::AdicionaPonto(int vertice,double x,double y){
    p[vertice].x = x;
    p[vertice].y = y;
}

// função adicionna e calcula peso para colocar nas arestas
void DigrafoM::AdicionaAresta(int origem,int destino){
    if(origem >= 0 && origem < _numvertice && destino >= 0 && destino <_numvertice){
        Matriz[origem][destino] = CalculaDistancia(origem,destino);
    }
    else{
        std::cerr<<"indice das vertices invalidos"<<std::endl;
    }
}

// essa função adiona os portais no grafo
void DigrafoM::AdicionaPortal(int origem,int destino){
    if(origem >= 0 && origem < _numvertice && destino >= 0 && destino < _numvertice){
        Matriz[origem][destino] = 0;
    }
    else{
        std::cerr<<"indice das vertices invalidas "<<std::endl;
    }
}





