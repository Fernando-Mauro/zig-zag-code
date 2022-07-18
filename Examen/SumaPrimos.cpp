#include <bits/stdc++.h>
#define MAX 40001
using namespace std;

void RellenarCriba(vector<int> &primos){
    bitset<MAX> criba;
    primos.push_back(1);
    
    criba.set();
    criba.reset(0);
    criba.reset(1);

    for(int i = 2; i < MAX; ++i){
        if (criba[i]){
            primos.push_back(i);
            for(int j = i*2; j < MAX; j+=i) {
                criba.reset(j);
            }
        }
    }
}

int main(){
    vector<int> primos;
    vector<int> Sumatoria;
    int suma;
    int contador = 0;
    int maximo;

    RellenarCriba(primos);

    cin >> suma;

    while (primos[contador] <= suma ) {
        maximo = primos[contador];
        contador++;
    }

    Sumatoria.push_back(maximo);
    contador = 0;

    for(int i = 0; i < primos.size() && suma >= 1; ++i) {
        suma -= maximo;
        while (primos[contador] <= suma)  {
            maximo = primos[contador];
            contador++;
        }
        contador = 0;
        Sumatoria.push_back(maximo);
    }

    for ( int i = 0; i < Sumatoria.size()-1; ++i ) {
        cout << Sumatoria[i] << " "; 
    }

    return 0;
}