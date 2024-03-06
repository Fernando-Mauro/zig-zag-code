#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int u64;
#define MAX 10000001
bitset<MAX> criba;
vector<u64> primos;

void cribaRelleno(){
    criba.set();
    criba.reset(0);
    criba.reset(1);

    u64 lim = sqrt(MAX);

    for(int i = 2; i <= lim+2; i++){
        if(criba[i]){
            primos.push_back(i);
            for(int m  = i*2; m < MAX; m+=i){
                criba.reset(m);
            }
        }
    }
    
}

map<u64, vector<u64>> numeros;

void factorizacion(vector<u64> num) {
    u64 value = num[0];
    u64 limite = sqrt(value) + 2;
    u64 calcul = value;
    for (int i = 0; i < primos.size(); i++) {
        if (calcul % primos[i] == 0) {
            int currentPrim = primos[i];
            bool found = false; // Bandera para controlar el bucle while
            while (calcul % primos[i] == 0 && !found) {
                calcul /= primos[i];
                cout << primos[i] << ' ';
                auto punt = numeros.find(calcul);
                if (punt != numeros.end()) {
                    auto it = numeros[calcul].begin();
                    ++it;
                    for (; it != numeros[calcul].end(); ++it) {
                        cout << *it << ' ';
                        numeros[value].push_back(*it);
                    }
                    found = true; // Establecer la bandera para salir del bucle
                    calcul = 1;
                } else {
                    numeros[value].push_back(primos[i]);
                }
            }
        }
        if (primos[i] > limite) break;
    }
    if (calcul > 1) {
        cout << calcul;
        numeros[value].push_back(calcul);
    }
    cout << '\n';
}


int main(){
    cribaRelleno();
    int tam;  cin >> tam;
    for(int m = 0; m < tam; m++){
        u64 tem; cin >> tem;
        numeros[tem].push_back(tem);
        factorizacion(numeros[tem]);
    }
    return 0;
}