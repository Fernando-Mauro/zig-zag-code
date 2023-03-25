#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& arreglo, int objetivo, int suma_actual, int index, vector<int>& elementos_actuales, vector<int>& mejor_combinacion) {
    if (index == arreglo.size()) { 
        if (((objetivo - suma_actual) >= 0) && abs(objetivo - suma_actual) < abs(objetivo - mejor_combinacion[0])) {
            mejor_combinacion[0] = suma_actual;
            mejor_combinacion.erase(mejor_combinacion.begin() + 1, mejor_combinacion.end());
            mejor_combinacion.insert(mejor_combinacion.end(), elementos_actuales.begin(), elementos_actuales.end());
        }
        return;
    }
    elementos_actuales.push_back(arreglo[index]);
    solve(arreglo, objetivo, suma_actual + arreglo[index], index + 1, elementos_actuales, mejor_combinacion);
    elementos_actuales.pop_back();
    solve(arreglo, objetivo, suma_actual, index + 1, elementos_actuales, mejor_combinacion);
}

int main() {
    int objetivo;
    while(cin >> objetivo){
            int n;
            cin >> n;
            vector<int> arreglo(n);

            for (int i = 0; i < n; i++) {
                cin >> arreglo[i];
            }

            vector<int> elementos_actuales;
            vector<int> mejor_combinacion = { INT_MAX };

            solve(arreglo, objetivo, 0, 0, elementos_actuales, mejor_combinacion);
            for (int i = 1; i < mejor_combinacion.size(); i++) {
                cout << mejor_combinacion[i] << " ";
            }
            cout << "sum:" << mejor_combinacion[0] << "\n";
    }
    return 0;
}