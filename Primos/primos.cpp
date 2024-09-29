#include <bits/stdc++.h>

using namespace std;

vector <bool> criba(1000000, true);
unordered_set <int> primos;

void llenarCriba() {
    for(int i = 2; i < criba.size(); ++i) {

        if(criba[i]) {
            primos.insert(i);

            for(int j = i * 2; j < criba.size(); j += i) {
                criba[j] = false;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int cantNumeros;
    cin >> cantNumeros;
    
    llenarCriba();

    int numero;
    while(cantNumeros--) {
        cin >> numero;
        if(primos.find(numero) != primos.end()) {
            cout << "Es primo" << '\n';
            break;
        } else {
            cout << "No es primo" << '\n';
        }
    }

    return 0;
}