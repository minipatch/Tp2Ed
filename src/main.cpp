#include <iostream>
#include <fstream>
#include <sstream>
#include "DigrafoM.hpp"
#include "DigrafoF.hpp"
#include <filadeprioridade.hpp>
#include <string>
#include <cctype> // Para isdigit
#include "algoritmo.hpp"

int main() {
    // int vertice = 0;
    // int trilha = 0;
    // int portais = 0;
    // std::string linha, aux1, aux2, aux3;

    // std::ifstream arquivo("src/arv.txt");

    // if (!arquivo.is_open()) {
    //     std::cerr << "Erro: não foi possível abrir o arquivo 'src/arv.txt'" << std::endl;
    //     return 1;
    // }

    // if (std::getline(arquivo, linha)) {
    //     std::cout << "Conteúdo da primeira linha: " << linha << std::endl;
    // } else {
    //     std::cerr << "Erro: não foi possível ler a primeira linha do arquivo" << std::endl;
    //     arquivo.close(); 
    //     return 1;
    // }

    // arquivo.close();

    // int numeros_encontrados = 0;

    // for (size_t i = 0; i < linha.size(); ++i) {
    //     if (isdigit(linha[i])) {
    //         if (numeros_encontrados == 0) {
    //             aux1 += linha[i]; // Concatenar caracteres para formar o número
    //         } else if (numeros_encontrados == 1) {
    //             aux2 += linha[i];
    //         } else if (numeros_encontrados == 2) {
    //             aux3 += linha[i];
    //         }
    //     } else if (linha[i] == ',' && numeros_encontrados < 3) {
    //         ++numeros_encontrados;
    //     }
    // }

    // std::stringstream ss1(aux1);
    // ss1 >> vertice;

    // std::stringstream ss2(aux2);
    // ss2 >> trilha;

    // std::stringstream ss3(aux3);
    // ss3 >> portais;


    
    int tam;

    std::cin>>tam;

    // Fila f(tam);

    // for(int i=0;i<tam;i++){
    //     int aux;
    //     std::cin>>aux;

    //     f.insert(aux);
    // }
    

    // for(int i=0;i<tam;i++){
    //     std::cout<<f.Limpa()<<std::endl;
    // }

    
    // DigrafoF grafo(tam);

    DigrafoM grafo2(tam);

    for(int i=0;i<tam;i++){
        int aux1,aux2,peso;
        std::cin>>aux1;
        std::cin>>aux2;
        std::cin>>peso;

        grafo2.adicionaaresta(aux1,aux2,peso);

        // grafo.adicionarAresta(aux1,aux2,peso);
    }



    // if(grafo.existeAresta(1,2) == true){
        // std::cout<<"existe aresta"<<std::endl;
    // }

    grafo2.print();


    Distrah dis;
    
    int origem = 0;
    
    dis.alg(grafo2,origem,4);




    return 0;
}
