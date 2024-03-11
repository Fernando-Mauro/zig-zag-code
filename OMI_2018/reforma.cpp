#include <bits/stdc++.h> 

using namespace std;

typedef unsigned long long int i64;

i64 solve(vector <i64> &buildings){
    i64 res = 1, tam = 1;
    i64 maxCurrent = 1;
    for(i64 i = 1; i < buildings.size(); ++i){
        if(buildings[i] < buildings[i - 1]){
            tam++;
        }else{
            res = max(res, tam);
            tam = 1;
        }
    }

    return max(res, tam);
}

int main(){
    i64 n;
    cin >> n;
    vector <i64> buildings(n, 0);

    for(i64 i = 0; i < n; ++i){
        cin >> buildings[i];
    }

    cout << solve(buildings);
    return 0;
}