#include <bits/stdc++.h>

#define optimizaIO() ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){
    optimizaIO();
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &e: A)cin >> e;
    vector<int> DP(N, INT32_MAX);
    DP[0] = 0;
    for(int i = 0; i < N-1; ++i){
        DP[i+1] = min(DP[i+1], DP[i] + abs(A[i] - A[i+1]));
        if(i + 2 < N){
            DP[i+2] = min(DP[i+2], DP[i] + abs(A[i] - A[i+2]));
        }
    }
    cout << DP[N-1] << "\n";
    return 0;
}