#include "filadeprioridade.hpp"
#include <stdexcept>
#include <algorithm>

Fila::Fila(int tamanho) : _tamanho(tamanho), count(0) {
    heap = new Elemento[_tamanho];
}

Fila::Fila() : _tamanho(0), count(0), heap(nullptr) {}

Fila::~Fila() {
    if (heap != nullptr) {
        delete[] heap;
    }
}

void Fila::restruturar() {
    Elemento* newHeap = new Elemento[_tamanho * 2];
    for (int i = 0; i < count; i++) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
    _tamanho *= 2;
}

void Fila::insert(Elemento element) {
    if (_tamanho == count) {
        restruturar();
    }
    heap[count] = element;
    heapifyUp(count);
    count++;
}

void Fila::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index].distancia < heap[parent].distancia) {
        std::swap(heap[index], heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void Fila::heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < count && heap[left].distancia < heap[smallest].distancia) {
        smallest = left;
    }
    if (right < count && heap[right].distancia < heap[smallest].distancia) {
        smallest = right;
    }
    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

bool Fila::Vazio() {
    return count == 0;
}

Elemento Fila::Limpa() {
    if (Vazio()) {
        throw std::runtime_error("Fila vazia");
    }

    Elemento min = heap[0];
    heap[0] = heap[--count];
    heapifyDown(0);

    return min;
}
