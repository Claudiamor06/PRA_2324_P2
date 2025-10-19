#include <iostream>
#include <vector>
#include <chrono>
#include "DyV.h"

void mostrarVector(const std::vector<int>& v) {
    for (int val : v)
        std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> desordenado{9, 3, 7, 1, 8, 2, 5, 4, 6, 0};

    std::cout << "Vector original:\n";
    mostrarVector(desordenado);

    auto start = std::chrono::system_clock::now();
    QuickSort(desordenado, 0, desordenado.size() - 1);
    auto end = std::chrono::system_clock::now();

    std::cout << "Vector ordenado:\n";
    mostrarVector(desordenado);

    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout << "Tiempo de ejecución: " << duration.count() << " ms" << std::endl;

    return 0;
}

