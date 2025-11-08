#include <bits/stdc++.h> 

typedef long long int i64;

using namespace std;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;
        
        i64 minNum = LONG_LONG_MAX;
        i64 maxNum= LONG_LONG_MIN;

        i64 temp;
        for(int i = 0; i < n; ++i){
            cin >> temp;
            minNum = min(temp, minNum);
            maxNum = max(temp, maxNum);
        }

        i64 x;
        cin >> x;
        string ans = "NO";
        if(minNum <= x && maxNum >= x)
            ans = "YES";

        cout << ans << "\n"; 
    }
    
    return 0;
}