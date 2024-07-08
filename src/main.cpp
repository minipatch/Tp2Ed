#include <iostream>
#include <fstream>
#include <sstream>
#include "DigrafoM.hpp"
#include "DigrafoF.hpp"
#include <filadeprioridade.hpp>
#include <string>
#include <cctype> // Para isdigit
#include "algoritmo.hpp"
#include "fila.hpp"
#include <cmath>


int Calculapeso(par& a1,par& a2){
    int dx = a2.x - a1.x;
    int dy = a2.y - a1.y;
    return std::sqrt(dx*dx + dy*dy);
}


int main() {


    // DigrafoM grafo;

    std::string linha;
    std::ifstream file("arquivo de leitura");
    int numvertices,numaresta,portais;



    if(!file.is_open()){
        std::cerr<< "erro em abrir o arquivo "<<std::endl;
        return 1;
    }
    
    //copia o numero de vertices,numero de arestas,numero de portais 
    file>>numvertices>>numaresta>>portais;

    FilaAux aux(numvertices);

    FilaAux aux2(portais);

    double x;
    double y;

    // copia a posição dos pontos com relação a plano
    for(int i=0;i<numvertices;i++){
        file>>x>>y;
        aux.insert(x,y);
    }

    // fala onde tem aresta
    int u,v;


    for(int i=0;i<numaresta;i++){
        file>>u>>v;
        // grafo.adicionaaresta(u,v);
    }




    // copia a energia e limite de portal que pode ser ultilizado

    // int limitPortal;

    // double energia;

    // file>>energia>>limitPortal;



    // calcula peso
    // par d1,d2;
    // int peso;

    
    // d1 = aux.remove();
    // d2 = aux.remove();

    // peso = Calculapeso(d1,d2);



    //usa o algoritmo de distrah para ver maior distancia
    // Distrah d;

    // d.alg(grafo,0,2);


    return 0;
}
