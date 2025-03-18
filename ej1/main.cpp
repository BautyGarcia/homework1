#include <iostream>
#include "main.h"
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    vector<vector<int> > matriz = crear_matriz(n);

    print_matriz(matriz);

    return 0;
}


vector<vector<int> > crear_matriz(int n) {
    vector<vector<int> > matriz(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Esta formula significa Nro de columna + (Nro de fila * Nro de columnas) + 1
            matriz[i][j] = j + (i  * n) + 1;
        }
    }

    return matriz;
}

void print_matriz(vector<vector<int> > matriz) {
    int n = matriz.size();
    
    // Recorro la matriz n^2 - 1 veces, con la division obtengo la fila y con el modulo obtengo la columna
    for (int i = n * n - 1; i >= 0; i--) {
        int value = matriz[i / n][i % n];
        cout << "M[" << i / n << "][" << i % n << "] = " << value << endl;
    }
}