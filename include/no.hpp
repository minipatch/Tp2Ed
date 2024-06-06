#ifndef NO_HPP
#define NO_HPP

#include <iostream>
#include <string>

class No{
    private:
        No* _prox;
        std::string _clareira;

    public:
        No();

        std::string getClareira();


        void setClareira(std::string Clareira);

        No* getprox();


        void setProx(No* prox);
};

#endif