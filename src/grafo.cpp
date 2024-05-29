#include "grafo.hpp"



Grafo::Grafo(int v)
{
    this-> Vertices = v;
    listadj = new ListaEncadeada[Vertices];
}


Grafo::~Grafo()
{
    delete[] listadj;
}


void Grafo::adicionaAresta(int v1,int v2,int peso)
{
    listadj[v1].adicionar(v2,peso);
    listadj[v2].adicionar(v1,peso);
}

ListaEncadeada Grafo::obterListaadj(int v)const
{
    return listadj[v];    
}

int Grafo::obterNumeroV()const 
{
    return Vertices;
}

void Grafo::exibirGrafo()
{
    for(int i=0;i<Vertices;i++)
    {
        std::cout<<i<<": ";
        No* temp = listadj[i].obterCabeca();
        while(temp){
            std::cout <<"("<< temp->getdestino()<<","<<temp->getPeso()<<")";
            temp = temp->getProx();
        }
    
    std::cout<<std::endl;
    }

}