#include <iostream>

using namespace std;

const int LOG = 17;
const int MAXN = 100001;

int n, q;
int a[MAXN];
int st[MAXN][LOG];
int lg[MAXN];

int query(int l, int r){
    int i = lg[r-l+1];
    return min(st[l][i], st[r - (1 << i) + 1][i]);
}

int main(){
    lg[1] = 0;  
    for(int i = 2; i <= MAXN; ++i){
        lg[i] = lg[i/2] + 1;
    }
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        st[i][0] = a[i];
    }
    for(int i = 1; i <= LOG; ++i){
        for(int j = 0; j + (1 << i) <= n; ++j){
            st[j][i] = min(st[j][i-1], st[j + (1 << (i-1))][i-1]);
        }
    }
    cin >> q;
    for(int i = 0; i < q; ++i){
        int l, r;   
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }
}