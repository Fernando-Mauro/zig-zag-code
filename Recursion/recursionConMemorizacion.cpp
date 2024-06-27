#include <bits/stdc++.h> 

using namespace std;

typedef unsigned long long int i64;

i64 counter = 0;

i64 memo[102][102][102];

i64 f(i64 a, i64 b, i64 c){
    if(memo[a][b][c] != 0){
        return memo[a][b][c];
    } 
    counter++;

    i64 min3 = min(a, min(b,c));

    if(min3 <= 3){
        memo[a][b][c] = a + (2 * b) + (3 * c);
        return memo[a][b][c];
    }else if(min3 > 3 && (a + b + c) == 100)
        return 0;
    else{
        memo[a][b][c] = f(a - 1, b - 1, c - 1 ) + f(a, b - 3, c - 3) + f(a / 2, b ,c);
        return memo[a][b][c];
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    i64 a, b, c;
    cin >> a >> b >> c;

    cout << f(a, b, c) % LONG_LONG_MAX << " " << counter << endl; 
    
    return 0;
}