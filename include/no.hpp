#ifndef NO_HPP
#define NO_HPP


#include <iostream>

class No{
    private:
        int _destino;

        int _peso;

        No* _prox;

    public:

        No();

        void setcounteudo(int counteudo);

        void setProx(No* p);

        int getdestino();

        No* getProx();

        int getPeso();
        
        void setPeso(int peso);

};






#endif