#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<int> ca(MAX ,0);
    for(int i = 0; i < 5; ++i) {
        cin >> n;
        while(n--){
            int pd, c;
            cin >> pd >> c;
            ca[pd] += c;
        }
    }
    for(int i = 0; i < MAX; ++i) {
        if(ca[i] > 0)cout << i << " " << ca[i] << endl;
    }
    return 0;
}