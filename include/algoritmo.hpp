#ifndef ALGORITMO_HPP
#define ALGORITMO_HPP

#include <cmath>
#include "filaprio.hpp"
#include "filaA.hpp"
#include <iostream>
#include "DigrafoF.hpp"
#include "filaM.hpp"
#include "DigrafoM.hpp"

class Algoritmo
{
private:
public:
    Algoritmo();


    // parte com Matriz
    double heuristica(DigrafoM &grafo,int vertice,int destino);

    void aStar(DigrafoM& grafo,int origem,int destino,double energia,int max_portais);

    void dijkstra(DigrafoM& grafo,int origem,int destino,double energia,int max_portais);


    // Função para calcular a heurística A* entre o nó atual e o destino
    double A_heuristica(const DigrafoF &grafo, int atual, int destino);

    // Implementação do algoritmo A* para encontrar o caminho do nó origem ao destino
    void a_Star(DigrafoF &grafo, int origem, int destino, double energia, int max_portais);

    // Implementação de um algoritmo dijkstra com algumas alterações
    void d_grafoF(DigrafoF &grafo, int origem, int destino, double energia, int max_portais);

};

#endif