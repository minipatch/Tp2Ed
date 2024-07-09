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
        std::cerr<<"indice das vertices invalidos1"<<std::endl;
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

double DigrafoM::CalculaDistancia(int p1,int p2){
    double dx =  p[p2].x - p[p1].x;
    double dy = p[p2].y - p[p1].y;

    return std::sqrt(dx*dx+dy*dy);
}


void DigrafoM::print() const{
    for(int i=0;i<_numvertice;i++){
        for(int j =0;j<_numvertice;j++){
            std::cout<<Matriz[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

int DigrafoM::getVertice()const{
    return _numvertice;
}

void DigrafoM::setEnergia(double s){
    _energia = s;
}

void DigrafoM::setQtdPortal(int q){
    _qtsportais = q;
}

double** DigrafoM::getMatriz(){
    return Matriz;
}


