#include <bits/stdc++.h> 
#define mod 1000000007

using namespace std;

typedef long long int i64;

i64 x[500000];
i64 y[500000];
int n;

int suma(char axis){
    i64 res = 0;
    i64 sum = 0;
    
    if(axis == 'x'){
        for(int i = 0; i < n; ++i){
            res += (((x[i] * i) % mod) - sum) % mod;
            sum += x[i];
        }
    }else{
        for(int i = 0; i < n; ++i){
            res += (((y[i] * i) % mod) - sum) % mod;
            sum += y[i];
        }
    }

    return res;
}

int solve(){
    sort(x, x + n);
    sort(y, y + n);
    
    i64 sumx = suma('x');
    i64 sumy = suma('y');

    return ((sumx + sumy) % mod);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    // vector <int> x(n);
    // vector <int> y(n);
    
    for(int i = 0; i < n; ++i){
        cin >> x[i];
        cin >> y[i];
    }

    cout << solve() << "\n";
    return 0;
}   