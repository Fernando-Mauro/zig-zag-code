#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct actual{
    ll x, y;
    friend bool operator<(const actual &a, const actual &b){
        if(a.x == b.x)return a.y > b.y;
        return a.x < b.x;
    }
};

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll N, K;
        vector<ll> A;
        cin >> N >> K;
        A.resize(N+1);
        priority_queue<actual> pq;
        for(ll i = 1; i <= N; ++i){
            cin >> A[i];
            pq.push({A[i], i});
        }
        while(!pq.empty()){
            auto ac = pq.top();
            pq.pop();
            ac.x-=K;
            if(ac.x <= 0){
                cout << ac.y << " ";
            }
            else if(ac.x > 0){
                pq.push(ac);
            }
        }
        cout << "\n";   
    }

    return 0;
}