#ifndef DIGRAFO_HPP
#define DIGRAFO_HPP

#include <iostream>
#include <iomanip>

class DigrafoM{
    private:
        int** matriz;
        int _numVertices;


    public:
        DigrafoM(int numvertices);

        DigrafoM();

        ~DigrafoM();

        void adicionaaresta(int origem,int destino);

        void removearesta(int origem,int destino);

        bool existearesta(int origem,int destino);

        void print() const;

        void adicionapeso(int peso,int destino,int origem);


        int getVertices() const;

        void ObterVizinhos(int vertice,int *vizinhos,int *pesos,int& count) const;

        void disktra();
};





#endif