#include <iostream>
#include <fstream>
#include <sstream>
#include "DigrafoM.hpp"
#include "DigrafoF.hpp"
#include <filadeprioridade.hpp>
#include <string>
#include <cmath>
#include <limits>


using namespace std;

// Heuristica para o algoritmo A* 


void dijkstra(DigrafoM& grafo, int origem, int dest, double energia, int max_portais) {
    int V = grafo.getVertice();
    double** Matriz = grafo.getMatriz();
    
    double** dist = new double*[V];
    int** predecessor = new int*[V];
    int** portals = new int*[V];
    bool** visited = new bool*[V];

    for (int i = 0; i < V; ++i) {
        dist[i] = new double[max_portais + 1];
        predecessor[i] = new int[max_portais + 1];
        portals[i] = new int[max_portais + 1];
        visited[i] = new bool[max_portais + 1];
        for (int j = 0; j <= max_portais; ++j) {
            dist[i][j] = numeric_limits<double>::infinity();
            predecessor[i][j] = -1;
            portals[i][j] = 0;
            visited[i][j] = false;
        }
    }

    dist[origem][0] = 0;
    Minheap pq(V * (max_portais + 1));
    pq.push({origem, 0, 0});

    while (!pq.vazio()) {
        Elemento u = pq.pop();
        int u_vertice = u.vertice;
        double u_distancia = u.distancia;
        int u_portais_usados = u.portais_usados;

        if (u_vertice == dest && u_distancia <= energia) {
            cout << 1 << endl;

            int current = dest;
            int current_portais = u_portais_usados;
            while (current != -1) {
                cout << current << " ";
                int prev = predecessor[current][current_portais];
                if (current_portais > 0 && Matriz[prev][current] == 0) {
                    current_portais--;
                }
                current = prev;
            }
            cout << endl;

            // Libera memória
            for (int i = 0; i < V; ++i) {
                delete[] dist[i];
                delete[] predecessor[i];
                delete[] portals[i];
                delete[] visited[i];
            }
            delete[] dist;
            delete[] predecessor;
            delete[] portals;
            delete[] visited;

            return;
        }

        if (u_distancia > energia || visited[u_vertice][u_portais_usados]) {
            continue;
        }

        visited[u_vertice][u_portais_usados] = true;

        for (int v = 0; v < V; ++v) {
            if (Matriz[u_vertice][v] != -1) {
                double peso = Matriz[u_vertice][v];
                int novos_portais_usados = u_portais_usados + (peso == 0 ? 1 : 0);

                if (novos_portais_usados <= max_portais && dist[v][novos_portais_usados] > dist[u_vertice][u_portais_usados] + peso) {
                    dist[v][novos_portais_usados] = dist[u_vertice][u_portais_usados] + peso;
                    predecessor[v][novos_portais_usados] = u_vertice;
                    pq.push({v, dist[v][novos_portais_usados], novos_portais_usados});
                }
            }
        }
    }

    cout << 0 << endl;

    // Libera memória
    for (int i = 0; i < V; ++i) {
        delete[] dist[i];
        delete[] predecessor[i];
        delete[] portals[i];
        delete[] visited[i];
    }
    delete[] dist;
    delete[] predecessor;
    delete[] portals;
    delete[] visited;
}

void dijastra(DigrafoF& grafo,int origem,int destino,double energia,int max_portais_){

}


int main() {


    std::ifstream file("arquivo de leitura");



    if(!file.is_open()){    
        std::cout<<"nao foi possivel abrir o arquivo"<<std::endl;
        return 1;
    }

    int n; // referente a vertices
    int m; // referente a aresta
    int k; // referente ao numero de portais




    // fazendo a leitura da primeira linha 
    file>>n>>m>>k;

    DigrafoM grafo(n);


    // ler as posições do ponto no plano cartesiano


    for(int i=0;i<n;i++){
        double x,y;
        file>>x>>y;
        grafo.AdicionaPonto(i,x,y);
    }

    // inserindo as arestas no grafo

    for(int i=0;i<m;i++){
        int u;
        int v;
        file>>u>>v;
        grafo.AdicionaAresta(u,v);
    }


    // inserindo os portais no grafo
    for(int i=0;i<k;i++){
        int u;
        int v;
        file>>u>>v;
        grafo.AdicionaPortal(u,v);
    }

    // energia e  quantos portais podem ser ultilizados 
    double s;
    int q; 

    file>>s>>q;

    // passando para classe a quantidade de energia,qtd de portal
    grafo.setEnergia(s);
    grafo.setQtdPortal(q);


    std::cout<<"tudo"<< std::endl;

    grafo.print();

    dijkstra(grafo,0,n-1,s,q);

    // a_star(grafo,0,n-1,s,q);
    
    return 0;
}
