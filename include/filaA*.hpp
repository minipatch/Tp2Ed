#ifndef FILAA
#define FILAA

#include <iostream>
#include <limits>

struct elementA{
    int vertice;
    double distancia;
    double f;
    int portais_usados;

    bool operator<(const elementA& other)const{
        return f > other.f;
    }
};


class Afila{
    private:
        elementA* heap;

        int _tamanho;
        int _capacidade;

        void heapifydown(int i);
        void heapifyup(int i);

    public:

        Afila(int capacidade);

        ~Afila();

        void push(elementA e);

        elementA pop();

        bool vazio() const;
};



#endif