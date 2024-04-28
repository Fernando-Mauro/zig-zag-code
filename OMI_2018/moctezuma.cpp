#include <vector>
#include "tesoro.h"

using namespace std;

void BuscaTesoros(int n, int m, int k) {
    int ultimaPosicion = 0;
    int fila, columna;
    int inicio, fin, mitad;
    vector<vector<int>> cuenta(n + 1, vector<int>(m + 1));
    
    if (k == 0)
        return;

    for (int i = 1; i <= k; i++) {
        inicio = ultimaPosicion + 1;
        fin = m;
        mitad = (inicio + fin) / 2;

        while (inicio < fin) {
            if (Preguntar(n, mitad) >= i) {
                fin = mitad;
            } else {
                inicio = mitad + 1;
            }
            mitad = (inicio + fin) / 2;
        }

        columna = inicio;

        for (int a = ultimaPosicion + 1; a < columna; a++) {
            for (int b = 0; b <= n; b++) {
                cuenta[b][a] = cuenta[b][a - 1];
            }
        }

        inicio = 1;
        fin = n;
        mitad = (inicio + fin) / 2;

        while (inicio < fin) {
            if (Preguntar(mitad, columna) == cuenta[mitad][columna - 1] + 1) {
                fin = mitad;
            } else {
                inicio = mitad + 1;
            }
            mitad = (inicio + fin) / 2;
        }

        fila = fin;

        for (int j = 1; j < fila; j++) {
            cuenta[j][columna] = cuenta[j][columna - 1];
        }
        for (int j = fila; j <= n; j++) {
            cuenta[j][columna] = cuenta[j][columna - 1] + 1;
        }

        Cavar(fila, columna);

        ultimaPosicion = columna;
    }
}
