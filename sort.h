#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

// Función para particionar el arreglo
template <typename T>
size_t particionar(T arr[], size_t bajo, size_t alto) {
    T pivote = arr[alto]; // Elegimos el último elemento como pivote
    size_t i = bajo - 1; // Índice del elemento más pequeño

    for (size_t j = bajo; j < alto; j++) {
        if (arr[j] <= pivote) {
            i++; // Incrementar el índice del elemento más pequeño
            swap(arr[i], arr[j]); // Intercambiar
        }
    }
    swap(arr[i + 1], arr[alto]); // Colocar el pivote en la posición correcta
    return i + 1; // Retornar el índice del pivote
}

// Función recursiva para aplicar QuickSort
template <typename T>
void QuickSort(T arr[], size_t bajo, size_t alto) {
    if (bajo < alto) {
        size_t pi = particionar(arr, bajo, alto); // Particionar el arreglo

        // Ordenar recursivamente los elementos antes y después de la partición
        QuickSort(arr, bajo, pi - 1);
        QuickSort(arr, pi + 1, alto);
    }
}

// Función para mostrar el arreglo
template <typename T>
void Print(ostream &os, T arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        os << arr[i] << " ";
    }
    os << endl;
}

void SortDemo();

#endif  // __QUICK_SORT_H__