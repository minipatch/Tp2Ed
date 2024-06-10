#include "fila.hpp"


FilaP::FilaP()
{
    
}

FilaP::FilaP(int max){
    this->contador = 0;
    this->nomax = max;

    fila = new NGFO::No[nomax];
}


FilaP::~FilaP()
{
    delete[] fila;
}

void FilaP::Heapifyup(int index)
{
    if(index == 0)
    {
        return;
    }

    int indexparterno = (index - 1)/2;

    if(fila[index].getClareira() > fila[indexparterno].getClareira())
    {
        NGFO::No aux = fila[indexparterno];

        fila[indexparterno] = fila[index];

        fila[index] = aux;

        Heapifyup(indexparterno);
    }
}


void FilaP::Heapifydown(int index)
{
    int leftindex = 2 * index + 1;
    int rightindex = 2 * index + 2;
    int ultimoIndex = index;

    if(leftindex < nomax && fila[leftindex].getClareira() > fila[ultimoIndex].getClareira())
    {
        ultimoIndex = leftindex;
    }

    if(rightindex<nomax && fila[rightindex].getClareira() > fila[ultimoIndex].getClareira())
    {
        ultimoIndex = rightindex;
    }


    if(ultimoIndex != index){
        NGFO::No aux = fila[index];
        fila[index] = fila[ultimoIndex];
        fila[ultimoIndex] = aux;
        Heapifydown(ultimoIndex);
    }
}

bool FilaP::ischeio(){
    return (contador == nomax);
}


void FilaP::enfileira(NGFO::No item)
{
    if(ischeio()){
        std::cout<<"a fila esta cheia"<<std::endl;
        return;
    }

    fila[contador] = item;
    Heapifyup(contador);
    contador++;
}

NGFO::No FilaP::top()
{
    if(contador == 0){
        throw std::out_of_range("a fila esta vazia");
    }

    return fila[0];
}

void FilaP::deseinfileira()
{
    if(contador == 0){
        throw std::out_of_range("a fila esta vazia");
    }

    fila[0] = fila[contador -1];
    contador -= 1;
    Heapifydown(0);
}