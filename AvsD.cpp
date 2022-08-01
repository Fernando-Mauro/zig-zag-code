#include <bits/stdc++.h>
#define MAX 5000010
using namespace std;

typedef long long int u64; 

bitset<MAX> criba;
vector<u64> primos;

void Rellenar() {
    criba.set();
    criba.reset(0); criba.reset(1);

    for ( int i = 2; i < MAX; ++i) {
        if ( criba[i] ) {
            primos.push_back(i);
            for ( int j = i*2; j < MAX; j+= i) {
                criba.reset(j);
            }
        }
    }
}
void obtener_factores(vector<u64>& u, u64 num) {
    for(u64 i = 0; i < primos.size() && primos[i]*primos[i] <= num; i++) {
    	if(num % primos[i] == 0) {
    		while(num % primos[i] == 0) {
    			num /= primos[i];
    		}
            u.push_back(primos[i]);
    	}
    }
    u.push_back(num);
}
int main() {
    
    u64 num1, num2;
    cin >> num1 >> num2;

    Rellenar();

    vector<u64> daniel;
    vector<u64> abigael;

    obtener_factores(daniel, num1);
    obtener_factores(abigael, num2);

    if (daniel.size() > abigael.size()) {
        cout << "Daniel" << endl;
    } else if(daniel.size() == abigael.size()) {
        cout << "Empate" << endl;
    } else {
        cout << "Abigael" << endl;
    }

    for (int i = 0; i < daniel.size(); ++i) {
        cout << daniel[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < abigael.size(); ++i) {
        cout << abigael[i] << " ";
    }
    cout << "\n";


    return 0;
}