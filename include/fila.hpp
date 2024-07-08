#ifndef FILAAUX_HPP
#define FILAAUX_HPP

#include <iostream>
#include <string>

struct par{
    double x;
    double y;
};


class FilaAux{
    private:
        int _tam;

        int _count;

        int _fin;

        int _inicio;

        par* vetor;
        
    public:
        FilaAux(int tam);

        ~FilaAux();

        bool isCheio();

        bool isVazio();

        void insert(double x,double y);

        par remove();        
};


#endif