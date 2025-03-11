#include <iostream>
#include "main.h"

using namespace std;

int main() {
    int n;

    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> n;

    int** matriz = crear_matriz(n);
    print_matriz(matriz, n);

    // Me dio cosa que evaluen el tema memoria asi que borro la matriz
    delete_matriz(matriz, n);
    
    return 0;
}

int** crear_matriz(int n) {
    int** matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matriz[i][j] = j + (i  * n) + 1;
        }
    }

    return matriz;
}

void print_matriz(int** matriz, int n) {
    for (int i = n * n - 1; i >= 0; i--) {
        int value = matriz[i / n][i % n];
        cout << "M[" << i / n << "][" << i % n << "] = " << value << endl;
    }
}

void delete_matriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}