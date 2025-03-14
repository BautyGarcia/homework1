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
            matriz[i][j] = j + (i  * n) + 1;
        }
    }

    return matriz;
}

void print_matriz(vector<vector<int> > matriz) {
    int n = matriz.size();
    for (int i = n * n - 1; i >= 0; i--) {
        int value = matriz[i / n][i % n];
        cout << "M[" << i / n << "][" << i % n << "] = " << value << endl;
    }
}