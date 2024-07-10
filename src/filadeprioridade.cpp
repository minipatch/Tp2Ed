#include "filadeprioridade.hpp"

Minheap::Minheap(int capacidade){
    this->_capacidade = capacidade;
    this->_tamanho = 0;
    heap = new Elemento[_capacidade];
}


Minheap::~Minheap(){
    delete[] heap;
}


void Minheap::push(Elemento e){
    if(_tamanho == _capacidade){
        return;
    }

    heap[_tamanho] = e;

    heapifyUp(_tamanho);

    _tamanho++;
}


Elemento Minheap::pop(){
    if(_tamanho  == 0){
        return Elemento{-1,std::numeric_limits<double>::infinity(),-1};
    }

    Elemento aux  = heap[0];
    heap[0] = heap[--_tamanho];
    heapifydown(0);

    return aux;
}


bool Minheap::vazio() const{
    return _capacidade == -0;
}


void Minheap::heapifydown(int i){
    int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < _tamanho && heap[left].distancia < heap[smallest].distancia)
            smallest = left;
        if (right < _tamanho && heap[right].distancia < heap[smallest].distancia)
            smallest = right;
        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapifydown(smallest);
        }

}

void Minheap::heapifyUp(int i) {
    int parent = (i - 1) / 2;
    while (i > 0 && heap[i].distancia < heap[parent].distancia) {
        std::swap(heap[i], heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

