#ifndef EDGE_HPP
#define EDGE_HPP


class Edge{
    private:
        int _peso;
        int _dest;
        Edge* _prox;
    
    public:

        Edge(int peso,int dest);

        int getPeso();

        int getDest();

        Edge* getprox();

        void setnext(Edge* n);
};





#endif