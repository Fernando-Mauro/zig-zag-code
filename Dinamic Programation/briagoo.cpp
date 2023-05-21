#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int i64;

i64 solve(vector <i64> &numeros){
    vector<vector< i64 >> dp(numeros.size() + 1, vector<i64>(numeros.size() + 1, 0));
    for (int i = 0; i < numeros.size(); i++) {
        dp[i][i] = numeros[i];
    }
    for (int k = 1; k < numeros.size(); k++) {
        for (int i = 0; i < numeros.size() - k; i++) {
            int j = i + k;
            dp[i][j] = max(numeros[i] + min(dp[i+2][j], dp[i+1][j-1]), numeros[j] + min(dp[i][j-2], dp[i+1][j-1]));
        }
    }
    return dp[0][numeros.size() - 1];
}

int main() {
    int N;
    cin >> N;
    vector<i64> numeros(N);
    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }
    cout << solve(numeros) << "\n";
    return 0;
}
