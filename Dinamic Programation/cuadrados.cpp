#include <bits/stdc++.h>

const int INVALIDO = -1;

using namespace std;

int memo[10001];

int solve(int n){
    if (n <= 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    if (memo[n] != INVALIDO){
        return memo[n];
    }

    int limite = sqrt(n);
    int contador = INT32_MAX;
    for (int i = 1; i <= limite; ++i){
        contador = min(contador, solve(n - i * i) + 1);
    }
    memo[n] = contador;
    return contador;
}

int main()
{
    int casos;
    cin >> casos;
    memset(memo, INVALIDO, sizeof(memo));
    while (casos--)
    {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }

    return 0;
}