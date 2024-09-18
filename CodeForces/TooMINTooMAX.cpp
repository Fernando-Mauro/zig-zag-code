#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int N;
        cin >> N;
        vector<int> A(N + 1, 0);
        for(int i = 1; i <= N; i++){
            cin >> A[i];
        }
        sort(A.begin() + 1, A.end());
        int i = 1, j = N, k = 2, L = N - 1;
        int total = abs(A[i] - A[j]) + abs(A[j] - A[k]) + abs(A[k] - A[L]) + abs(A[L] - A[i]);
        cout << total << "\n";

     }
    return 0;
}