//https://omegaup.com/arena/problem/El-k-esimo-numero-primo/
#include<bits/stdc++.h>
#define MAX 80000
using namespace std;

bitset<MAX> criba;
vector<long long int> primes;

void rellenar() {
    criba.set();
    criba.reset(0);
    criba.reset(1);

    for(int i = 2; i < MAX; i++){
        if(criba[i]){
            primes.push_back(i);
            for(int j = i * 2; j < MAX; j+= i ){
                criba.reset(j);
            }
        }   
    }
}


int main() {
    rellenar();

    int pos;
    cin >> pos;

    cout << primes[pos-1] << endl;

    return 0;
}