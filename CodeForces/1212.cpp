#include <bits/stdc++.h>

using namespace std;

bool is_beautiful(vector<int> &A){
	sort(A.begin(), A.end());
	bool ok = false;
	for(auto &e: A){
		for(int i = 0; i < A.size(); ++i){
			cout << e << " " << A[i] << "[[\n";
			if(A[i] % e == 0){
				ok = true;
			}else ok = false;
		}
		if(ok)return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin >> tt;
	
	while(tt--){
		int N;
		cin >> N;
		vector<int> A(N);
		for(auto &e: A)cin >> e;
		if(is_beautiful(A)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	
	
	return 0;
}