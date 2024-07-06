#include "DigrafoF.hpp"


No::No(int destino,int peso){
    this->_destino  = destino;
    this->_peso = peso;
    this->_prox = nullptr;
}

No::No(){}

Lista::Lista(){}


DigrafoF::DigrafoF(int numvertices){
    this->_numVertices = numvertices;
    
    adj = new Lista[_numVertices];

    for(int i=0;i<_numVertices;i++){
        adj[i].cabeca = nullptr;
    }
}

DigrafoF::~DigrafoF(){

    for(int i=0;i<_numVertices;i++){
        destruirLista(adj[i].cabeca);
    }
    delete[] adj;
}

void DigrafoF::adicionarAresta(int origem,int destino,int peso){
    if(origem>=0 && origem < _numVertices && destino>= 0 && destino<_numVertices){
        No* novoNo = criaNo(destino,peso);

        novoNo->_prox = adj[origem].cabeca;
        adj[origem].cabeca = novoNo;
    }
    
    else{
        std::cerr<<"indice invalido"<<std::endl;
    }    
}

void DigrafoF::removerAresta(int origem,int destino){
    if(origem >= 0 && origem < _numVertices && destino >= 0 && destino< _numVertices){
        No* atual = adj[origem].cabeca;
        No* anterior = nullptr;
    
        while(atual != nullptr && atual->_destino != destino){
            anterior = atual;
            atual = atual->_prox;
        }

        if(atual == nullptr){
            return; 
        }

        if(anterior == nullptr){
            adj[origem].cabeca = atual->_prox;
        }
        else{
            anterior->_prox = atual->_prox;
        }
        delete atual;
    }
    else{
        std::cerr<<"indice invalido"<<std::endl;
    }
}


bool DigrafoF::existeAresta(int origem,int destino) const{
    if(origem>= 0 && origem<_numVertices && destino >= 0 && destino<_numVertices){
        No* atual = adj[origem].cabeca;
        
        while(atual != nullptr){
            if(atual->_destino  == destino){
                return true;
            }
            atual = atual->_prox;
        }
    }
    return false;
}


void DigrafoF::imprimirGrafo() const{
    for(int i=0;i<_numVertices;i++){
        std::cout<<  i << ": ";
        No* atual = adj[i].cabeca;
        
        while(atual != nullptr){
            std::cout<<"("<< atual->_destino<<",peso: "<<atual->_peso<<")";
            atual = atual->_prox;
        }

        std::cout<< std::endl;
    }
}

No* DigrafoF::criaNo(int destino,int peso){
    No* novo = new No;


    novo->_destino = destino;
    novo->_peso = peso;
    novo->_prox = nullptr;

    return novo;  
}

void DigrafoF::destruirLista(No* no){
    while(no != nullptr){
        No* aux = no;
        no  = no->_prox;
        delete aux;
    }
}