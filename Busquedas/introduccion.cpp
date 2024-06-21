#include <bits/stdc++.h> 

using namespace std;


int pasos = 0;

int busquedaBinaria(vector <int> &numeros, int n){
    int inicio = 0;
    int final = numeros.size() - 1; 

    while(inicio != final){
        pasos++;
        int mitad = (inicio + final) / 2;
        if(numeros[mitad] == n){
            return mitad;
        }else if(numeros[mitad] > n){
            inicio = mitad - 1;
        }else if(numeros[mitad] < n){
            final = mitad + 1;
        }
    }
    return -1;
}

// 9 6 7 4 1 2 5
// 3 -> NO
// 2 -> SI

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector <int> numeros(n);

    for(int i = 0; i < n; ++i){
        cin >> numeros[i];
    }

    // sort(numeros.begin(), numeros.end()); // n * log2(n)

    int q;
    cin >> q;
    cout << busquedaBinaria(numeros, q) << "\n";

    return 0;
}