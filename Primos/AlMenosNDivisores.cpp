#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MAXP 100
#define MAXE 64
typedef long double lld;

int N = 0, M = 0;
bitset <MAXN> criba;
lld primos[MAXP][MAXE];
// lld DP[MAXN][MAXP];
//  la dp es de 10k por 100 > 1millon de casillas
vector <vector<lld>> DP(MAXN,vector <lld> (MAXP,-1));

//Resuelve usando una DP
lld resolver(int n, int p) {
    // n son los divisores a buscar
    // p aun no se lo que es xD
    if (n == 1){
        return 1;
    }else if (DP[n][p] < 0) {
        DP[n][p] = INFINITY;
        // ciclo que va desde 2 hasta n o hasta 64 (la maxima potencia a la cual podemos elevar 2)
        for (int i = 2; i <= n && i < MAXE; i++){
            DP[n][p] = min(DP[n][p], resolver((n + i - 1) / i, p + 1) * primos[p][i - 1]);
        }
    }
    return DP[n][p];
}

void rellenarCriba(){
    // MAXP son los maximos primos
    criba.set();
    criba.reset(0);
    criba.reset(1);
    for(int i = 0; M < MAXP && i < MAXN; ++i){
        if(criba[i]){
            // el numero i elevado a 0
            primos[M][0] = 1;
            // el numero i elevado a 1
            primos[M++][1] = i;
             for( int j = i*2; j < MAXN; j+=i ) {
                criba.reset(j);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    //Calcula los primeros primos MAXN PRIMOS
    rellenarCriba();
    //Calcula las potencias de dichos primos que entran en un long long
    // en pocas palabras los primos los comienza a elevar a 1 2 3 ....... hasta 64
    for (int i = 0; i < M; i++){
        for (int j = 2; j < MAXE; j++){
            primos[i][j] = primos[i][j - 1] * primos[i][1];
        }
    }
       
    //Inicializa la matriz DP EN -1
    // for (int i = 0; i < MAXN; i++){
    //      for (int j = 0; j < MAXP; j++){
    //         DP[i][j] = -1;
    //      }
    // }
    cout << setprecision(0) << fixed << resolver(N, 0) << endl;
    return 0;
}