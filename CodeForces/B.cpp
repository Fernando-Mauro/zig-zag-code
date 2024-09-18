	#include <bits/stdc++.h>
	#define ll long long int
	using namespace std;


	void solve(){
		int size;
		cin >> size;
		vector<int> a = {1};
		for(int i = 1, j = 3; i < size; ++i, j += 3){
			a.push_back(j);
		}
		int i = 0;
		while(next_permutation(a.begin(), a.end())){
			if(i == size)break;
			for(auto e: a){
				cout << e;
			}
			cout << "\n";
		++i;
		}
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