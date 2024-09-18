#include <bits/stdc++.h>
#define ll long long int
#define LOG 26
#define MAX 50002

using namespace std;

int N, M;
ll ST[LOG][MAX];

int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        cin >> ST[0][i];
    }
    for(int i = 1; i <= LOG; ++i){
        for(int j = 0; j + (1 << i) <= N; ++j){
            ST[i][j] = max(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
        }
    }
    int ans = 0;
    for(int i = 0; i < M; ++i){
        int l, r;
        cin >> l >> r;
        --l, --r;
        if(abs(l - r) <= 1)ans++;
        else if(l < r){
            ++l, --r;
            int j = log2(r - l + 1);
            int res = max(ST[j][l], ST[j][r - (1 << j) + 1]);
            if(res <= ST[0][l-1])ans++;
        }else {
            --l, ++r;
            int j = log2(l - r + 1);
            int res = max(ST[j][r], ST[j][l - (1 << j) + 1]);
            if(res <= ST[0][r - 1])ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}