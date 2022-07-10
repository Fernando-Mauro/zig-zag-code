//https://omegaup.com/arena/problem/Juanito-y-los-primos/
#include <bits/stdc++.h>

using namespace std;

#define MAX 10000001

bitset <MAX> criba;
vector <long long int> primos;

void rellenarCriba(){
    // cambia a true todos los valores
    criba.set();
    // cambia a false esos dos valores
    criba.reset(0);
    criba.reset(1);
    for(int i = 2; i < MAX; i++){
        if(criba[i]){
            primos.push_back(i);
            for(int j = i * 2; j < MAX; j+= i ){
                criba.reset(j);
            }
        }   
    }
}

bool esPrimo(unsigned long long int number){
    int divisores = 1;
    long long int raiz = sqrt(number);
    for(int i = 0; i < primos.size() && primos[i] <= number; ++i){
        int vecesPrimo = 1;
        while(number % primos[i] == 0){
            vecesPrimo++;
            number /= primos[i];
        }
        divisores *= vecesPrimo;
    }
    if(number != 1){
        divisores *= 2;
    }

    if(divisores == 2){
        // Es primo
        return true;
    }
    return false;
}
int main(){
    unsigned long long int n;
    cin >> n;
    rellenarCriba();
    if(esPrimo(n)){
        cout << "si es primo";
    }else{
        cout << "no es primo";
    }
    return 0;
}