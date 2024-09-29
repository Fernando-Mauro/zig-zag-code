// Trajineras
// https://omegaup.com/arena/problem/Trajineras/#problems
#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

vector<int> robots;
vector<i64> sumas;

void precalcularSumatorias() {
    for (int i = 0; i < robots.size(); ++i) {
        sumas[i] = robots[i];
        if (i > 0) {
            sumas[i] += sumas[i - 1];
        }
    }
}

i64 sumatoriaEnRango(int ini, int fin) {
    if (ini > 0) {
        return sumas[fin] - sumas[ini - 1];
    }
    return sumas[fin];
}

bool esPosibleFormarGruposSinExcederCarga(int tamGrupo, i64 cargaTotal) {
    if (tamGrupo == 0) {
        return true;
    }
    for (int i = 0; i <= robots.size() - tamGrupo; ++i) {
        if (sumatoriaEnRango(i, i + tamGrupo - 1) > cargaTotal) {
            return false;
        }
    }
    return true;
}

// Busca el tamanio maximo del grupo de robots contiguos, cuyo peso no excede la carga total.
// Implementa una busqueda binaria (upper_bound) para probar de manera optima los valores posibles del rango.
int buscarTamanioGrupo(i64 cargaTotal) {
    int ini = 0; // El minimo posible es equivalente a un grupo de tamanio 1.
    int fin = robots.size(); // El maximo posible es equivalente a un grupo que incluye todos los robots.
    while (ini < fin) {
        int mitad = ini + (fin - ini + 1) / 2;
        if (esPosibleFormarGruposSinExcederCarga(mitad, cargaTotal)) {
            ini = mitad;
        }
        else {
            fin = mitad - 1;
        }
    }
    return ini;
}

int main() {
    int numRobots;
    i64 cargaTotal;
    
    cin >> numRobots >> cargaTotal;
    // Asignar el tamanio adecuado a los vectores
    robots.resize(numRobots);
    sumas.resize(numRobots);

    for (int i = 0; i < numRobots; ++i) {
        cin >> robots[i];
    }

    precalcularSumatorias();
    cout << buscarTamanioGrupo(cargaTotal);

    return 0;
}