#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N + 1, 0), P(N + 1), B;
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    for(int i = 1; i <= K; ++i){
        B.push_back(A[i]);
    }
    for(int i = 1; i <= N; ++i){
        P[i] = P[i - 1] + A[i];
    }
    int init = 1, cmp = P[K];
    for(int i = K + 1; i <= N; ++i){
        int Ac_sum = P[i] - A[init];

        if(cmp - Ac_sum > 0){
            B.push_back(cmp - Ac_sum);
        }
        cout << cmp - Ac_sum << "\n";
        ++init;
        B.push_back(A[i]);
    }
    for(auto e: B)cout << e << " ";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }

    return 0;
}