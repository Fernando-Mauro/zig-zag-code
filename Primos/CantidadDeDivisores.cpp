#include <bits/stdc++.h> 

#define MAX 1000000
// 1 * 10^5 -> byte

using namespace std;

vector <bool> criba(MAX, true);
vector <int> primos;

// Generar primos
void fillCriba(){
    
    // Iniciamos en 2
    for(int i = 2; i <= MAX; i++){
        // Iterar sus multiplos
        if(criba[i]){
            primos.insert(i);
            
            for(int j = i * 2; j <= MAX; j += i){
                criba[j] = false;
            }
        }
    }
}

// 10
// 2 3 5 7
// 10 / 2 = 5 2, 5

int countDivisors(int current){
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fillCriba();
    int n;
    cin >> n;
    if(primos.find(n) != primos.end()){
        cout << "si es primo";
        
    }else{
        cout << "no es primo";

    }
    return 0;
}