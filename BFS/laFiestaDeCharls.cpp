// https://omegaup.com/course/ooi-2024-verde/assignment/fase-1-2#problems
#include <bits/stdc++.h> 

typedef long long int i64;
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map <i64, i64> friends;
    
    i64 ubication;
    
    while(n--){
        cin >> ubication;
        friends[ubication]++;
    }

    i64 minim = INT_MAX;
    
    for(auto dude : friends){
        i64 sum = 0;

        for(auto dudeNested: friends){
            sum += abs((dude.first - dudeNested.first) * dude.second);
        }
        minim = min(sum, minim);
    }

    cout << minim;
    return 0;
}