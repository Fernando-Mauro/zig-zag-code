#include <bits/stdc++.h>
using namespace std;
#define MAXN 10010
#define MAXP 100
#define MAXE 64
typedef long double lld;

int N, M, criba[MAXN];
lld primos[MAXP][MAXE];
lld DP[MAXN][MAXP];

//Resuelve usando una DP
lld Resolver(int n, int p) {
    if (n == 1)
        return 1;
    else if (DP[n][p] < 0) {
        DP[n][p] = INFINITY;
        for (int i = 2; i <= n && i < MAXE; i++)
            DP[n][p] = min(DP[n][p], Resolver((n + i - 1) / i, p + 1) * primos[p][i - 1]);
    }
    return DP[n][p];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    //Precalcula los primeros 10,000 primos
    for (int i = 2; M < MAXP && i < MAXN; i++)
        if (!criba[i]) {
            criba[i] = i;
            primos[M][0] = 1;
            primos[M++][1] = i;
            for (int j = i * i; j < MAXN; j += i){
                criba[j] = i;
            }
        }
    //Precalcula las potencias de dichos primos que entran en un long long
    for (int i = 0; i < M; i++)
        for (int j = 2; j < MAXE; j++)
            primos[i][j] = primos[i][j - 1] * primos[i][1];

    //Inicializa la DP
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXP; j++)
            DP[i][j] = -1;
    cout << setprecision(0) << fixed << Resolver(N, 0);
    return 0;
}