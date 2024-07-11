#include "filaA*.hpp"

Afila::Afila(int capacidade){
    this->_tamanho = 0;
    
    this->_capacidade = capacidade;

    heap  = new elementA[_capacidade];
}


Afila::~Afila(){
    delete[] heap;
}

void Afila::heapifydown(int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < _tamanho && heap[left].f < heap[smallest].f)
        smallest = left;
    if (right < _tamanho && heap[right].f < heap[smallest].f)
        smallest = right;
    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        heapifydown(smallest);
    }
}


void Afila::heapifyup(int i){
    int parent = (i - 1) / 2;
    while (i > 0 && heap[i].f < heap[parent].f) {
        std::swap(heap[i], heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}



void Afila::push(elementA e){
    if(_tamanho == _capacidade){
        std::cerr<<"a fila esta cheia"<<std::endl;
        return;
    }

    heap[_tamanho] = e;

    heapifyup(_tamanho);

    _tamanho++;
}


elementA Afila::pop(){
    if(_tamanho == 0){
        return elementA{-1,std::numeric_limits<double>::infinity(),std::numeric_limits<double>::infinity(),-1};
    }
    elementA aux = heap[0];

    heap[0] = heap[--_tamanho];
    heapifydown(0);

    return aux;
}


bool Afila::vazio() const{
    return _tamanho == 0;
}