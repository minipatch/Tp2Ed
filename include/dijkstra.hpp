#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "grafo.hpp"

class dijkstra
{
    private:

    public:

    dijkstra();

    static void Executa(const Grafo& grafo,int inicio);

    static int mindistancia(int dist[],bool visited[],int Vertice);

    void print();


};






#endif