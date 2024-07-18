#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>
#include "filaprio.hpp"
#include "algoritmo.hpp"
#include <chrono>

int main()
{

    std::ifstream file("arquivodeleitura.txt");

    if (!file.is_open())
    {
        std::cout << "nao foi possivel abrir o arquivo" << std::endl;
        return 1;
    }

    int n; // referente a vertices
    int m; // referente a aresta
    int k; // referente ao numero de portais

    // fazendo a leitura da primeira linha
    file >> n >> m >> k;

    DigrafoF grafo1(n);

    DigrafoM grafo(n);
    // ler as posições do ponto no plano cartesiano

    for (int i = 0; i < n; i++)
    {
        double x, y;
        file >> x >> y;
        grafo.AdicionaPonto(i,x,y);
        grafo1.adicionaPonto(i, x, y);
    }

    // inserindo as arestas no grafo

    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        file >> u >> v;
        grafo.AdicionaAresta(u,v);
        grafo1.AdicionaAresta(u, v);
    }

    // inserindo os portais no grafo
    for (int i = 0; i < k; i++)
    {
        int u;
        int v;
        file >> u >> v;
        grafo.AdicionaPortal(u,v);
        grafo1.AdicionaPortal(u, v);
    }

    // energia e  quantos portais podem ser ultilizados
    double s;
    int q;

    file >> s >> q;

    // passando para classe a quantidade de energia,qtd de portal

    grafo.setEnergia(s);
    grafo.setQtdPortal(q);

    grafo1.setEnergia(s);
    grafo1.setQtdPortal(q);

    Algoritmo a;

    a.d_grafoF(grafo1, 0, n - 1, s, q);

    a.a_Star(grafo1, 0, n - 1, s, q);

    a.dijkstra(grafo,0,n-1,s,q);

    a.aStar(grafo,0,n-1,s,q);
    


    return 0;

}
