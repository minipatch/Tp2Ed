#ifndef NO_HPP
#define NO_HPP


#include <iostream>

class No{
    private:
        int destino;

        No* prox;

    public:

        No();

        void setcounteudo(int counteudo);

        void setProx(No* p);

        int getdestino();

        No* getProx();

};






#endif