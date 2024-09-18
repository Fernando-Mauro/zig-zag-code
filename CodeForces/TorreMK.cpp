#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        vector<int> A;
        cin >> N;
        A.resize(N);
        int DP[N+1][2];
        memset(DP, INF, sizeof(DP));      
        for(auto &e : A)cin >> e;
            DP[0][1] = 0;
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < 2; ++j){
                    for(int k = 1; k <= min(N-i, 2); ++k){
                        int dificiles = A[i] + (k > 1 ? A[i+1] : 0);
                        DP[i + k][!j] = min(DP[i + k][!j], DP[i][j] + j * dificiles);
                    }
                }
            }
        cout << min(DP[N][0], DP[N][1]) << "\n";
    }
    return 0;
}