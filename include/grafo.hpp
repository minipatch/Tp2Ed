#ifndef GRAFO_HPP

#include <iostream>
#include "fila.hpp"
#include "edge.hpp"

class Grafo{
    private:
        int** matrizAdjacencia;

        int verticesMax; 
    public:

        Grafo(int verticesmax);

        ~Grafo();

        void addEdge(int u,int verticesmax,int weight);


        
        
};







#endif