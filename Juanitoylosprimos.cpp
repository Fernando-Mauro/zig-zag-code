//https://omegaup.com/arena/problem/Juanito-y-los-primos/
#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

#define MAX 10000001
using namespace std;

typedef long long int ll;


void fill_sieve(vector<int> &primes) {
    bitset<MAX> sieve;

    sieve.set();
    sieve.reset(0); sieve.reset(1);
    for( int i = 2; i < MAX; i++ ) {
        if( sieve[i] ) {
            primes.push_back(i);
            for( int j = i*2; j < MAX; j+=i ) {
                sieve.reset(j);
            }
        }
    }
}

bool count_divisors(ll number, vector<int> &primes) {
    int divisors = 1;

    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= number; i++) {
        int factor_times = 1;
        while (number % primes[i] == 0) {
            number /= primes[i];
            factor_times ++;
        }
        divisors *= factor_times;
    }

    if (number != 1) {
        divisors*=2;
    }

    if ( divisors == 2 ) {
        return false;
    }else {
        return true;
    }
}

int main(){

    ll  num;
    // Calcular factores primos hasta la raiz del máximo posible
    vector<int> primes;
    fill_sieve(primes);


    cin >> num;
        
    if ( count_divisors(num, primes) == true ) {
        cout << "no es primo" << endl;
    }else {
        cout << "si es primo";
    }

    return 0;
}