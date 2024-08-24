#include <bits/stdc++.h>

using namespace std;

int mpp[2000001];

int main(){
    int k = 0;
    int N;
    scanf("%d", &N);
    vector<long long int> a(N);
    long long int xr = 0, cnt = 0;
    mpp[xr]++;
    for(int i = 0; i < N; ++i){
        scanf("%lld", &a[i]);
        xr ^= a[i];
        long long int x = xr ^ 0;
        cnt += mpp[x];
        mpp[xr]++;
    }
    printf("%lld", cnt);

    return 0;
}