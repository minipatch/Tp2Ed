#include "filaprio.hpp"

direct::Minheap::Minheap(int capacidade)
{
    this->_capacidade = capacidade;
    this->_tamanho = 0;

    heap = new Elemento[_capacidade];
}

direct::Minheap::~Minheap()
{
    delete[] heap;
}

void direct::Minheap::heapifyUp(int i)
{
    int pai = (i - 1) / 2;
    while (i > 0 && heap[i].distancia < heap[pai].distancia)
    {
        std::swap(heap[i], heap[pai]);
        i = pai;
        pai = (i - 1) / 2;
    }
}

void direct::Minheap::heapifyDown(int i)
{
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < _tamanho && heap[esq].distancia < heap[menor].distancia)
    {
        menor = esq;
    }
    if (dir < _tamanho && heap[dir].distancia < heap[menor].distancia)
    {
        menor = dir;
    }
    if (menor != i)
    {
        std::swap(heap[i], heap[menor]);
        heapifyDown(menor);
    }
}

void direct::Minheap::push(const Elemento &e)
{
    if (_tamanho == _capacidade)
    {
        std::cerr << "capaciddade maxima atingida" << std::endl;
        return;
    }

    heap[_tamanho] = e;

    heapifyUp(_tamanho);

    _tamanho++;
}

direct::Elemento direct::Minheap::pop()
{
    if (_tamanho == 0)
    {
        return {-1, std::numeric_limits<double>::infinity(), -1, -1};
    }
    Elemento aux = heap[0];
    heap[0] = heap[--_tamanho];
    heapifyDown(0);
    return aux;
}

bool direct::Minheap::vazio() const
{
    return _tamanho == 0;
}