// https://omegaup.com/arena/problem/oro
#include <bits/stdc++.h>

using namespace std;

void busqueda(vector<int> &rocas, int requerido, int index, int oroActual, int &minOroActual) {
    
    if (oroActual >= requerido) {
        if(oroActual < minOroActual){
            minOroActual = oroActual;
        }
    }
    
    for (int i=index+1; i<rocas.size(); i++) {
        busqueda(rocas, requerido, i, oroActual + rocas[i], minOroActual);
    }
}

int main() {
    int  rocasTotales;
    int requerido;
    
    cin >> rocasTotales;
    cin >>requerido;
    vector<int> rocas(rocasTotales);

    for (int i = 0; i < rocasTotales; i++) {
        cin >> rocas[i];
    }
        
    int minOroActual = INT_MAX;
    
    for (int i=0; i< rocasTotales; i++) {
        busqueda(rocas, requerido, i, rocas[i], minOroActual);
    }
    
    
    int restante = minOroActual - requerido;
    
    cout << restante;
    
    return (0);
}