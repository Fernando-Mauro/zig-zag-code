#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long int> two(33, 0);
    for(int i = 0; i <= 32; ++i){
        two[i] = (1 << i);
    }
    
    int tt;
    cin >> tt;
    while(tt--){
        long long int x, mp = 0;
        cin >> x;
        vector<int> h;
        while(x > 0){
            for(int i = 31; i >= 0; --i){
                if(x >= abs(two[i])){
                    x -= two[i];
                    mp = i;
                    h.push_back(i);
                }
            }
        }
        for(int i = 0; i < h.size(); ++i){
            cout << h[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}