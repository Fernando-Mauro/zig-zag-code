#include  <bits/stdc++.h>

using namespace std;


int solve(int n, int m, string binary, int pos){
    if(pos < 0){
        return 1;
    }

    if(n == 1)
        return n;

    if (n == 0)
        return 1;
        
    if(binary[pos] == '0'){
        int res = solve(n,m, binary, pos - 1);
        return ((res %  m) * (res % m)) % m;
    }
    if(binary[pos] == '1'){
        binary[pos] = '0';
        int res = solve(n, m, binary, pos);

        return ((res % m) * (res % m) * (n % m)) % m;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    string binary;
    cin >> binary;
    cout << solve(n, m, binary, binary.size() - 1);
}