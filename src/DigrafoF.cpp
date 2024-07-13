#include "DigrafoF.hpp"

DigrafoF::DigrafoF(int numvertices)
{
    this->_numvertice = numvertices;

    ListadeAdjacencia = new Noadjacencia *[_numvertice];
    for (int i = 0; i < _numvertice; i++)
    {
        ListadeAdjacencia[i] = nullptr;
    }

    p = new ponto[_numvertice];
}

DigrafoF::~DigrafoF()
{
    for (int i = 0; i < _numvertice; i++)
    {
        Noadjacencia *atual = ListadeAdjacencia[i];
        while (atual != nullptr)
        {
            Noadjacencia *temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }
    delete[] ListadeAdjacencia;
    delete[] p;
}

void DigrafoF::adicionaPonto(int vertice, double x, double y)
{
    p[vertice].x = x;
    p[vertice].y = y;
}

double DigrafoF::calculaDistancia(int p1, int p2)
{
    double dx = p[p2].x - p[p1].x;
    double dy = p[p2].y - p[p1].y;
    return std::sqrt(dx * dx + dy * dy);
}

void DigrafoF::AdicionaAresta(int origem, int destino)
{
    if (origem >= 0 && origem < _numvertice && destino >= 0 && destino < _numvertice)
    {
        double peso = calculaDistancia(origem, destino);
        Noadjacencia *novoNo = new Noadjacencia{destino, peso, ListadeAdjacencia[origem]};
        ListadeAdjacencia[origem] = novoNo;
    }
    else
    {
        std::cerr << "Vertices invalidas" << std::endl;
    }
}

void DigrafoF::AdicionaPortal(int origem, int destino)
{
    if (origem >= 0 && origem < _numvertice && destino >= 0 && destino < _numvertice)
    {
        Noadjacencia *novoNo = new Noadjacencia{destino, 0, ListadeAdjacencia[origem]};
        ListadeAdjacencia[origem] = novoNo;
    }
    else
    {
        std::cerr << "Vertices invalidas" << std::endl;
    }
}

void DigrafoF::print() const
{
    for (int i = 0; i < _numvertice; i++)
    {
        std::cout << "Vertice " << i << ": ";
        Noadjacencia *atual = ListadeAdjacencia[i];
        while (atual != nullptr)
        {
            std::cout << "(" << atual->destino << ", " << atual->peso << ") ";
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }
}

int DigrafoF::getVerice() const
{
    return _numvertice;
}

void DigrafoF::setQtdPortal(int q)
{
    _qtsportais = q;
}

void DigrafoF::setEnergia(double s)
{
    _energia = s;
}

int DigrafoF::getQtdPortal()
{
    return _qtsportais;
}

double DigrafoF::getEnergia()
{
    return _energia;
}

double *DigrafoF::getCordenada(int vertice) const
{
    static double cordenada[2];
    if (vertice >= 0 && vertice < _numvertice)
    {
        cordenada[0] = p[vertice].x;
        cordenada[1] = p[vertice].y;
    }
    else
    {
        std::cerr << "Indice de vertice invalido" << std::endl;
        cordenada[0] = 0.0;
        cordenada[1] = 0.0;
    }
    return cordenada;
}