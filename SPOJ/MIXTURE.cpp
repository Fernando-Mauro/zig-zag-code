#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAXN = 110;

int N;
int A[MAXN];
ll dp[MAXN][MAXN], ac[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> N){
        for(int i = 1; i <= N; ++i){
            cin >> A[i];
            ac[i] = ac[i-1] + A[i];
            dp[i][i] = 0;
        }
        for(int i = N; i >= 1; --i){
            for(int j = i+1; j <= N; ++j){
                dp[i][j] = LLONG_MAX;
                for(int l = i; l < j; ++l){
                    ll kl = (ac[l] - ac[i-1]) % 100;
                    ll kr = (ac[j] - ac[l]) % 100;
                    dp[i][j] = min(dp[i][j], dp[i][l] + dp[l+1][j] + (kl * kr));
                }
            }
        }
        cout << dp[1][N] << "\n";
    }

    return 0;
}