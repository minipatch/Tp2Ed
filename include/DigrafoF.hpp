#ifndef DIGRAFO_HPP
#define DIGRAFO_HPP

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

// Estrutura que representa um ponto no plano 2D.
struct ponto
{
    double x, y;
};

// Classe que representa um dígrafo (grafo dirigido) com funcionalidades adicionais.
class DigrafoF
{
private:
    int _numvertice;
    int _qtsportais;
    double _energia;
    ponto *p;

public:
    // Lista de adjacência representada como um array de ponteiros para Noadjacencia.
    Noadjacencia **ListadeAdjacencia;

    DigrafoF(int numvertices);
    ~DigrafoF();

    // Adiciona um ponto (coordenadas x e y) a um vértice específico.
    void adicionaPonto(int vertice, double x, double y);

    // Adiciona uma aresta de origem a destino no dígrafo.
    void AdicionaAresta(int origem, int destino);

    // Adiciona um portal (aresta com características especiais) de origem a destino.
    void AdicionaPortal(int origem, int destino);

    // Calcula a distância entre dois pontos (vértices) no plano 2D.
    double calculaDistancia(int p1, int p2);

    void print() const;

    int getVerice() const;

    void setQtdPortal(int q);

    void setEnergia(double s);

    int getQtdPortal();

    double getEnergia();

    double *getCordenada(int vertice) const;
};

#endif