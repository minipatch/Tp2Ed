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


int main() {


    DigrafoM grafo;

    std::string linha;
    std::ifstream file("arquivo de leitura");
    int numvertices,numaresta,portais;



    if(!file.is_open()){
        std::cerr<< "erro em abrir o arquivo "<<std::endl;
        return 1;
    }
    

    file>>numvertices>>numaresta>>portais;

    FilaAux aux(numvertices);

    FilaAux aux2(portais);

    double x;
    double y;

    for(int i=0;i<numvertices;i++){
        file>>x>>y;
        aux.insert(x,y);
    }

    int u,v;
    
    for(int i=0;i<numaresta;i++){
        file>>u>>v;
        grafo.adicionaaresta(u,v);
    }


    // for(int i=0;i<portais;i++){
    //     file>>u>>v;
    //     aux2.insert(u,v);
    // }


    double energia;

    int limitPortal;

    file>>energia>>limitPortal;
    

    Distrah d;

    d.alg(grafo,0,2);


    return 0;
}
