#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>

struct Ponto{
    double x;
    double y;
};


class DigrafoM{
    private:
        int _numvertice;
        Ponto  *p;
        double **Matriz;

    public:

        DigrafoM(int numvertices);

        ~DigrafoM();

        void adicionarAresta();

        void AdicionaPonto(int vertice,double x,double y);

        void AdicionaAresta(int origem,int destino);

        void AdicionaPortal(int origem,int destino);

        double CalculaDistancia(int p1,int p2);

        void print() const;

        int getVertice() const;

};




#endif 