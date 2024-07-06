#ifndef DIGRAFOF
#define DIGRAFOf

#include <iostream>


class No{
    private:
        int _destino;
        No* _prox;
        int _peso;
    
    public:
        No();

        No(int destino,int peso);

        friend class Lista;
        friend class DigrafoF;
};

class Lista{
    private:
        No* cabeca;

    public:
        Lista();
        
        friend class No;
        friend class DigrafoF;
};


class DigrafoF{
    private:

        int _numVertices;

        Lista *adj;

        No* criaNo(int destino,int peso);

        void destruirLista(No* no);

    public:
        DigrafoF(int numvertices);

        ~DigrafoF();

        void adicionarAresta(int origem,int destino,int peso);

        void removerAresta(int origem,int destino);
        
        bool existeAresta(int origem,int destino) const;

        void imprimirGrafo() const;        
};





#endif 