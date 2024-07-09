#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <cmath>

struct Ponto{
    double x;
    double y;
};


class DigrafoM{
    private:

        int _numvertice;
        int _qtsportais;
        double _energia;
        Ponto  *p;
        double **Matriz;

    public:

        DigrafoM(int numvertices);

        ~DigrafoM();

        void AdicionaPonto(int vertice,double x,double y);

        void AdicionaAresta(int origem,int destino);

        void AdicionaPortal(int origem,int destino);

        double CalculaDistancia(int p1,int p2);

        void print() const;

        int getVertice() const;


        void setEnergia(double s);

        void setQtdPortal(int q);

        double** getMatriz();
};




#endif 