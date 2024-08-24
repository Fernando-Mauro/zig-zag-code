#include <bits/stdc++.h>

using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> A(N + 1, 1), prefix(N + 1, 1);

	for(int i = 0; i < N; ++i){
		cin >> A[i];
		prefix[i + 1] = prefix[i] * A[i];
	}
	for(auto e: prefix)cout << e << " ";
	cout << "\n";
	for(auto e: A)cout << e << " ";
	cout << "\n";
	for(int i = 1; i <= N; ++i){
		
	}
	cout << "aaaa\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while(tt--)solve();

	return 0;
}