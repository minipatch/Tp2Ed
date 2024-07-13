#include <iostream>
#include <fstream>
#include <sstream>
#include "DigrafoM.hpp"
#include "DigrafoF.hpp"
#include <filadeprioridade.hpp>
#include <string>
#include <filaA*.hpp>
#include <cmath>
#include <limits>
#include "filaprio.hpp"
// parte da analise
void d_grafoF(DigrafoF& grafo, int origem, int destino, double energia, int max_portais) {
    int n = grafo.getVerice();
    double* distancias = new double[n];
    int* predecessores = new int[n];
    double** energia_restante = new double*[n];
    for (int i = 0; i < n; ++i) {
        energia_restante[i] = new double[max_portais + 1];
    }

    for (int i = 0; i < n; ++i) {
        distancias[i] = std::numeric_limits<double>::infinity();
        predecessores[i] = -1;
        for (int j = 0; j <= max_portais; ++j) {
            energia_restante[i][j] = -1;
        }
    }

    distancias[origem] = 0;
    energia_restante[origem][0] = energia;

    direct::Minheap fila(n);
    fila.push({origem, 0, energia, 0});

    while (!fila.vazio()) {
        direct::Elemento u = fila.pop();
        Noadjacencia* adj = grafo.ListadeAdjacencia[u.vertice];

        while (adj != nullptr) {
            int v = adj->destino;
            double peso = adj->peso;
            double nova_energia_restante = u.energia_restante - peso;
            int novos_portais_usados = u.portais_usados;

            if (peso == 0) {
                novos_portais_usados++;
            }

            if (nova_energia_restante >= 0 && novos_portais_usados <= max_portais) {
                if (distancias[v] > u.distancia + peso || energia_restante[v][novos_portais_usados] < nova_energia_restante) {
                    distancias[v] = u.distancia + peso;
                    predecessores[v] = u.vertice;
                    energia_restante[v][novos_portais_usados] = nova_energia_restante;
                    fila.push({v, distancias[v], nova_energia_restante, novos_portais_usados});
                }
            }

            adj = adj->proximo;
        }
    }

    if (distancias[destino] != std::numeric_limits<double>::infinity()) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    delete[] distancias;
    delete[] predecessores;
    for (int i = 0; i < n; ++i) {
        delete[] energia_restante[i];
    }
    delete[] energia_restante;
}


double a_heuristica(const DigrafoF& grafo, int atual, int destino) {
    double* coordenadas_atual = grafo.getCordenada(atual);
    double* coordenadas_destino = grafo.getCordenada(destino);
    double dx = coordenadas_destino[0] - coordenadas_atual[0];
    double dy = coordenadas_destino[1] - coordenadas_atual[1];
    return std::sqrt(dx*dx + dy*dy);
}

void a_Star(DigrafoF& grafo, int origem, int dest, double energia, int max_portais) {
    int V = grafo.getVerice();
    Noadjacencia** ListadeAdjacencia = grafo.ListadeAdjacencia;

    double** dist = new double*[V];
    int** predecessor = new int*[V];
    bool** visited = new bool*[V];

    for (int i = 0; i < V; ++i) {
        dist[i] = new double[max_portais + 1];
        predecessor[i] = new int[max_portais + 1];
        visited[i] = new bool[max_portais + 1];
        for (int j = 0; j <= max_portais; ++j) {
            dist[i][j] = std::numeric_limits<double>::infinity();
            predecessor[i][j] = -1;
            visited[i][j] = false;
        }
    }

    dist[origem][0] = 0;
    direct::Minheap pq(V * (max_portais + 1));
    pq.push({origem, 0, 0, 0});

    while (!pq.vazio()) {
        direct::Elemento u = pq.pop();
        int u_vertice = u.vertice;
        double u_distancia = u.distancia;
        int u_portais_usados = u.portais_usados;

        if (u_vertice == dest && u_distancia <= energia) {
            std::cout << 1 << std::endl;

            int current = dest;
            int current_portais = u_portais_usados;
            while (current != -1) {
                std::cout << current << " ";
                int prev = predecessor[current][current_portais];
                if (current_portais > 0 && ListadeAdjacencia[prev]->peso == 0) {
                    current_portais--;
                }
                current = prev;
            }

            // Libera memória
            for (int i = 0; i < V; ++i) {
                delete[] dist[i];
                delete[] predecessor[i];
                delete[] visited[i];
            }
            delete[] dist;
            delete[] predecessor;
            delete[] visited;

            return;
        }

        if (u_distancia > energia || visited[u_vertice][u_portais_usados]) {
            continue;
        }

        visited[u_vertice][u_portais_usados] = true;

        Noadjacencia* adj = ListadeAdjacencia[u_vertice];
        while (adj != nullptr) {
            int v = adj->destino;
            double peso = adj->peso;
            int novos_portais_usados = u_portais_usados + (peso == 0 ? 1 : 0);
            double distancia_atualizada = u_distancia + (peso == 0 ? grafo.calculaDistancia(u_vertice, v) : peso);

            if (novos_portais_usados <= max_portais && dist[v][novos_portais_usados] > distancia_atualizada) {
                dist[v][novos_portais_usados] = distancia_atualizada;
                predecessor[v][novos_portais_usados] = u_vertice;
                double h = a_heuristica(grafo, v, dest); // Heurística sem considerar portais
                pq.push({v, dist[v][novos_portais_usados], dist[v][novos_portais_usados] + h, novos_portais_usados});
            }

            adj = adj->proximo;
        }
    }

    std::cout << 0 << std::endl;

    // Libera memória
    for (int i = 0; i < V; ++i) {
        delete[] dist[i];
        delete[] predecessor[i];
        delete[] visited[i];
    }
    delete[] dist;
    delete[] predecessor;
    delete[] visited;
}

// parte do trabalho
double heuristica(DigrafoM &grafo, int vertice, int dest)
{
    double *coord_vertice = grafo.getCordenada(vertice);
    double *coord_dest = grafo.getCordenada(dest);
    double dx = coord_dest[0] - coord_vertice[0];
    double dy = coord_dest[1] - coord_vertice[1];
    return std::sqrt(dx * dx + dy * dy); // Distância euclidiana
}

void aStar(DigrafoM &grafo, int origem, int dest, double energia, int max_portais)
{
    int V = grafo.getVertice();
    double **Matriz = grafo.getMatriz();

    double **dist = new double *[V];
    int **predecessor = new int *[V];
    bool **visited = new bool *[V];

    for (int i = 0; i < V; ++i)
    {
        dist[i] = new double[max_portais + 1];
        predecessor[i] = new int[max_portais + 1];
        visited[i] = new bool[max_portais + 1];
        for (int j = 0; j <= max_portais; ++j)
        {
            dist[i][j] = std::numeric_limits<double>::infinity();
            predecessor[i][j] = -1;
            visited[i][j] = false;
        }
    }

    dist[origem][0] = 0;
    Afila pq(V * (max_portais + 1));
    pq.push({origem, 0, 0, 0});

    while (!pq.vazio())
    {
        elementA u = pq.pop();
        int u_vertice = u.vertice;
        double u_distancia = u.distancia;
        int u_portais_usados = u.portais_usados;

        if (u_vertice == dest && u_distancia <= energia)
        {
            std::cout << 1 << std::endl;

            int current = dest;
            int current_portais = u_portais_usados;
            while (current != -1)
            {
                // std::cout << current << " ";
                int prev = predecessor[current][current_portais];
                if (current_portais > 0 && Matriz[prev][current] == 0)
                {
                    current_portais--;
                }
                current = prev;
            }

            // Libera memória
            for (int i = 0; i < V; ++i)
            {
                delete[] dist[i];
                delete[] predecessor[i];
                delete[] visited[i];
            }
            delete[] dist;
            delete[] predecessor;
            delete[] visited;

            return;
        }

        if (u_distancia > energia || visited[u_vertice][u_portais_usados])
        {
            continue;
        }

        visited[u_vertice][u_portais_usados] = true;

        for (int v = 0; v < V; ++v)
        {
            if (Matriz[u_vertice][v] != -1)
            {
                double peso = Matriz[u_vertice][v];
                int novos_portais_usados = u_portais_usados + (peso == 0 ? 1 : 0);

                // Considera a distância normal entre vértices se um portal foi usado
                double distancia_atualizada = u_distancia + (peso == 0 ? grafo.CalculaDistancia(u_vertice, v) : peso);

                if (novos_portais_usados <= max_portais && dist[v][novos_portais_usados] > distancia_atualizada)
                {
                    dist[v][novos_portais_usados] = distancia_atualizada;
                    predecessor[v][novos_portais_usados] = u_vertice;
                    double h = heuristica(grafo, v, dest); // Heurística sem considerar portais
                    pq.push({v, dist[v][novos_portais_usados], dist[v][novos_portais_usados] + h, novos_portais_usados});
                }
            }
        }
    }

    std::cout << 0 << std::endl;

    // Libera memória
    for (int i = 0; i < V; ++i)
    {
        delete[] dist[i];
        delete[] predecessor[i];
        delete[] visited[i];
    }
    delete[] dist;
    delete[] predecessor;
    delete[] visited;
}

void dijkstra(DigrafoM &grafo, int origem, int dest, double energia, int max_portais)
{
    int V = grafo.getVertice();
    double **Matriz = grafo.getMatriz();

    double **dist = new double *[V];
    int **predecessor = new int *[V];
    int **portals = new int *[V];
    bool **visited = new bool *[V];

    for (int i = 0; i < V; ++i)
    {
        dist[i] = new double[max_portais + 1];
        predecessor[i] = new int[max_portais + 1];
        portals[i] = new int[max_portais + 1];
        visited[i] = new bool[max_portais + 1];
        for (int j = 0; j <= max_portais; ++j)
        {
            dist[i][j] = std::numeric_limits<double>::infinity();
            predecessor[i][j] = -1;
            portals[i][j] = 0;
            visited[i][j] = false;
        }
    }

    dist[origem][0] = 0;
    matriz::Minheap pq(V * (max_portais + 1));
    pq.push({origem, 0, 0});

    while (!pq.vazio())
    {
        matriz::Elemento u = pq.pop();
        int u_vertice = u.vertice;
        double u_distancia = u.distancia;
        int u_portais_usados = u.portais_usados;

        if (u_vertice == dest && u_distancia <= energia)
        {
            std::cout << 1 << std::endl;

            int current = dest;
            int current_portais = u_portais_usados;
            while (current != -1)
            {
                // std::cout << current << " ";
                int prev = predecessor[current][current_portais];
                if (current_portais > 0 && Matriz[prev][current] == 0)
                {
                    current_portais--;
                }
                current = prev;
            }

            // Libera memória
            for (int i = 0; i < V; ++i)
            {
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

        if (u_distancia > energia || visited[u_vertice][u_portais_usados])
        {
            continue;
        }

        visited[u_vertice][u_portais_usados] = true;

        for (int v = 0; v < V; ++v)
        {
            if (Matriz[u_vertice][v] != -1)
            {
                double peso = Matriz[u_vertice][v];
                int novos_portais_usados = u_portais_usados + (peso == 0 ? 1 : 0);

                if (novos_portais_usados <= max_portais && dist[v][novos_portais_usados] > dist[u_vertice][u_portais_usados] + peso)
                {
                    dist[v][novos_portais_usados] = dist[u_vertice][u_portais_usados] + peso;
                    predecessor[v][novos_portais_usados] = u_vertice;
                    pq.push({v, dist[v][novos_portais_usados], novos_portais_usados});
                }
            }
        }
    }

    std::cout << 0 << std::endl;

    // Libera memória
    for (int i = 0; i < V; ++i)
    {
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

int main()
{

    std::ifstream file("arquivo de leitura");

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

    DigrafoM grafo(n);
    DigrafoF grafo1(n);

    // ler as posições do ponto no plano cartesiano

    for (int i = 0; i < n; i++)
    {
        double x, y;
        file >> x >> y;
        grafo.AdicionaPonto(i, x, y);
        grafo1.adicionaPonto(i,x,y);
    }

    // inserindo as arestas no grafo

    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        file >> u >> v;
        grafo.AdicionaAresta(u, v);
        grafo1.AdicionaAresta(u,v);
    }

    // inserindo os portais no grafo
    for (int i = 0; i < k; i++)
    {
        int u;
        int v;
        file >> u >> v;
        grafo.AdicionaPortal(u, v);
        grafo1.AdicionaPortal(u,v);
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

    std::cout << "tudo" << std::endl;

    // grafo.print();

    // grafo1.print();


    // dijkstra(grafo, 0, n - 1, s, q);

    // aStar(grafo, 0, n - 1, s, q);


    d_grafoF(grafo1,0,n-1,s,q);


    a_Star(grafo1,0,n-1,s,q);

    return 0;
}
