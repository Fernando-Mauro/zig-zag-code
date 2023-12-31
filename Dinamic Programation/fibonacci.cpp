#include <bits/stdc++.h> 

using namespace std;

typedef long long int i64;

void solve(i64 n, vector <i64> &memo){
    memo[0] = 0;
    for(i64 i = 1; i <= n; ++i){
        if(i==1) 
            memo[i] = 1;
        else
            memo[i] = memo[i - 1] + memo[i - 2];
        printf("%llu ", memo[i]);
    }
}

int main(){
    i64 n;
    scanf("%llu", &n);
    vector <i64> memo(n + 10, 0);
    memo[0] = 0;
    memo[1] = 1;
    solve(n, memo);
    return 0;
}