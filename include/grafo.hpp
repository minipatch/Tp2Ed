#ifndef GRAFO_HPP

#include <iostream>
#include <no.hpp>


class Grafo{
    private:
        int maxClareiras;

        bool  isportal;

        int portal;

        int trilhas;

        int peso;

        No* vetor;
        
        int** matrizAdjacente;


    public:

        Grafo(int Clareiras,int trilhas,int portal);

        ~Grafo();

        bool getisPortal(int linha,int coluna);    

        void gerargrafo(int vertice,int peso);
};







#endif