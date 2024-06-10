#ifndef NO_HPP
#define NO_HPP

#include <iostream>
#include <string>

namespace NGFO{

    class No
    {
    private:
        int _clareira;

    public:
        No();

        int getClareira();

        void setClareira(int Clareira);

        No *getprox();

        void setProx(No *prox);
    };
}
#endif