#include <iostream>
#include <cmath>
#include <limits>
#include <fstream>

struct Noadjacencia
{
    int destino;
    double peso;
    Noadjacencia *proximo;
};

struct ponto
{
    double x, y;
};

class DigrafoF
{
private:
    int _numvertice;
    int _qtsportais;
    double _energia;
    ponto *p;

public:
    Noadjacencia **ListadeAdjacencia;

    DigrafoF(int numvertices);
    ~DigrafoF();
    void adicionaPonto(int vertice, double x, double y);
    void AdicionaAresta(int origem, int destino);
    void AdicionaPortal(int origem, int destino);
    double calculaDistancia(int p1, int p2);
    void print() const;
    int getVerice() const;
    void setQtdPortal(int q);
    void setEnergia(double s);
    int getQtdPortal();
    double getEnergia();
    double *getCordenada(int vertice) const;
};