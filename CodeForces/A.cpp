#include <bits/stdc++.h>

using namespace std;

void solve(){
	int N, K;
    cin >> N >> K;
    map<int, int> MINS;
    vector<int> A(N), B;
    for(auto &e: A)cin >> e;
    B = A;
    sort(A.begin(), A.end());
    for(int i = 0; i < K; ++i){
        MINS.insert({A[i], 1});
    }
    for(int i = 0; i < K; ++i){
        if(MINS.find(B[i]) != MINS.end()){
            MINS.erase(B[i]);
        }
    }
    cout << MINS.size() << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while(tt--)
		solve();
	return 0;
}