#include <bits/stdc++.h> 

using namespace std;

vector <int> people;

typedef long long int i64;

bool canEntryInNHours(int h, i64 n){
    
    for(int i = 0; i < people.size(); ++i){
        int hours = people[i] / n;
        
        h -= hours;
        if(people[i] % n != 0)
            h--; 
    }
     return (h < 0) ? false : true;
}

 i64 solve(int  h){
    i64 start = 1;
    i64 end = 1000000000;

    while(start < end){
        i64 middle = start + (end - start) / 2;

        if(canEntryInNHours(h, middle)){
            end = middle;
        }else{
            start = middle + 1;
        }

    }
    return end;
}
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, h;
    cin >> n >> h;
    people.resize(n);

    for(int i = 0; i < n; ++i){
        cin >> people[i];
    }

    cout << solve(h);


    return 0;
}