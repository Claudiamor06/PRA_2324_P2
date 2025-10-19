#ifndef DYV_H
#define DYV_H

#include <vector>
#include <iostream>

// Búsqueda binaria en vector ascendente
int BusquedaBinaria(int x, const std::vector<int>& v, int ini, int fin) {
    if (ini > fin) {
        std::cout << "No se encuentra en el array\n";
        return -1;
    }
    int medio = (ini + fin) / 2;
    if (v[medio] == x) {
        return medio;
    } else if (v[medio] > x) {
        return BusquedaBinaria(x, v, ini, medio - 1);
    } else {
        return BusquedaBinaria(x, v, medio + 1, fin);
    }
}

// Búsqueda binaria en vector descendente
int BusquedaBinaria_INV(int x, const std::vector<int>& v, int ini, int fin) {
    if (ini > fin) {
        std::cout << "No se encuentra en el array\n";
        return -1;
    }
    int medio = (ini + fin) / 2;
    if (v[medio] == x) {
        return medio;
    } else if (v[medio] < x) {
        return BusquedaBinaria_INV(x, v, ini, medio - 1);
    } else {
        return BusquedaBinaria_INV(x, v, medio + 1, fin);
    }
}

// Partition usando el último elemento como pivote
int Partition(std::vector<int>& v, int ini, int fin) {
    int pivote = v[fin];
    int i = ini - 1;

    for (int j = ini; j < fin; ++j) {
        if (v[j] <= pivote) {
            ++i;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[fin]);
    return i + 1;
}

// QuickSort usando el último elemento como pivote
void QuickSort(std::vector<int>& v, int ini, int fin) {
    if (ini < fin) {
        int p = Partition(v, ini, fin);
        QuickSort(v, ini, p - 1);
        QuickSort(v, p + 1, fin);
    }
}


#endif

