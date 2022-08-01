#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
typedef long double lld;

int N = 0, M = 0;
bitset <MAX> criba;
vector <int> primos;
void rellenarCriba(){
    // MAXP son los maximos primos
    criba.set();
    criba.reset(0);
    criba.reset(1);
    for(int i = 0; i < MAX; ++i){
        if(criba[i]){
            primos.push_back(i);
             for( int j = i*2; j < MAX; j+=i ) {
                criba.reset(j);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    rellenarCriba();
    return 0;
}