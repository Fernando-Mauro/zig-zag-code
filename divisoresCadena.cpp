//https://omegaup.com/arena/problem/Divisores-de-una-cadena
#include <bits/stdc++.h>

using namespace std;

int main(){
    string cadena;
    cin >> cadena;
    int total = 0;
    for(int i = 0; i < cadena.size(); i++){
        cadena[i] =toupper(cadena[i]);
        int letra = (int) cadena[i];
        total += letra;
    }
    int contador = 2;
    for(int i = 2; i <= (total / 2); i++){
        if(total % i == 0){
            contador++;
        }
    }
    cout << contador;
    return 0;
}