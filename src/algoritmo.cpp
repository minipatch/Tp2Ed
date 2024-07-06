#include "algoritmo.hpp"
#include <limits>
#include <iostream>

Distrah::Distrah() {}

void Distrah::alg(const DigrafoM& grafo, int origem, int destino) {
    int n = grafo.getVertices();

    int* distancia = new int[n];
    int* prev = new int[n];

    Fila pq(n);

    for (int i = 0; i < n; i++) {
        distancia[i] = std::numeric_limits<int>::max();
        prev[i] = -1;
    }

    distancia[origem] = 0;
    pq.insert({0, origem});

    while (!pq.Vazio()) {
        Elemento u = pq.Limpa();

        int* vizinhos = new int[n];
        int* pesos = new int[n];
        int count = 0;

        grafo.ObterVizinhos(u.vertice, vizinhos, pesos, count);

        for (int i = 0; i < count; i++) {
            int v = vizinhos[i];
            int peso = pesos[i];
            int alt = u.distancia + peso;

            if (alt < distancia[v]) {
                distancia[v] = alt;
                prev[v] = u.vertice;
                pq.insert({alt, v});
            }
        }

        delete[] vizinhos;
        delete[] pesos;
    }

    std::cout << "Distância do vértice " << origem << " para " << destino << ": " << distancia[destino] << std::endl;

    std::cout << "Caminho mais curto: ";
    imprimirCaminho(destino, prev, origem);
    std::cout << std::endl;

    delete[] distancia;
    delete[] prev;
}

void Distrah::imprimirCaminho(int destino, int* prev, int origem) {
    if (destino == origem) {
        std::cout << origem;
        return;
    } else if (prev[destino] == -1) {
        std::cout << "Caminho não encontrado";
        return;
    }

    imprimirCaminho(prev[destino], prev, origem);
    std::cout << " -> " << destino;
}
