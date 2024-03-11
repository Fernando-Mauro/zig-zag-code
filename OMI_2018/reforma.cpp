#include <bits/stdc++.h> 

using namespace std;

typedef unsigned long long int i64;
vector <i64> buildings;

i64 solve(){
    i64 maximus = 1;
    i64 before = -1;
    i64 maxCurrent = 1;
    for(i64 i = 0; i < (buildings.size() - 1); ++i){
        while(buildings[i + 1] <= buildings[i]){
            maxCurrent++;
            ++i;
        }
        maximus = max(maxCurrent, maximus);
        maxCurrent = 1;
    }

    return (maximus != -1) ? maximus : 1;
}

int main(){
    i64 n;
    cin >> n;
    buildings.resize(n + 1);

    for(i64 i = 0; i < n; ++i){
        cin >> buildings[i];
    }

    cout << solve();
    return 0;
}