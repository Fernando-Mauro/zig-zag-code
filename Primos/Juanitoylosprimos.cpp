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
    // 0 ->no son primos
    criba.reset(1);
    // 1 -> no son primos 
    for(int i = 2; i < MAX; i++){
        if(criba[i]){
            primos.push_back(i);
            for(int j = i * 2; j < MAX; j+= i ){
                criba.reset(j);
            }
        }   
    }
}

int countDivisors(unsigned long long int current){
    int divisors = 1;
    
    // Iterar sobre los primos generados por la criba
    for (int i = 0; i < primos.size(); ++i) {
        
        // Matematicas pero no se pq xD
        if (primos[i] * primos[i] > current) break;
        
        // 10
        // 2 3 5 7
        int exponent = 0;
        while (current % primos[i] == 0) {
            // 10 % 2 == 0
            //  10 /= 2 = 5
            current /= primos[i];
            ++exponent;
        }
        // 5
        divisors *= (exponent + 1);
    }

    // Si el número restante es mayor que 1, es primo y contribuye con un divisor más
    if (current > 1) divisors *= 2;
    return divisors;
}

int main(){
    unsigned long long int n;
    cin >> n;
    rellenarCriba();
    if(countDivisors(n) == 2){
        cout << "si es primo";
    }else{
        cout << "no es primo";
    }
    return 0;
}