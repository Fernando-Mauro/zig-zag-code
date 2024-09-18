#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) (x).size()

const int MAXN = 1e3 + 5;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int N, M, C;
long long int MONEY[MAXN];
vector<vector<long long int>> adj(MAXN);

int main(){
	setIO("time");
	cin >> N >> M >> C;
	for(int i = 0; i < N; ++i)cin >> MONEY[i];
	for(int i = 0; i < M; ++i){
		long long int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
	}
	vector<vector<long long int>> dp(MAXN+1, vector<long long int>(N, -1));
	dp[0][0] = 0;
	long long int answer = 0;
	for(int i = 0; i < MAXN; ++i){
		for(int j = 0; j < N; ++j){
			if(dp[i][j] != -1){
				for(int e: adj[j]){
					dp[i+1][e] = max(dp[i+1][e], dp[i][j] + MONEY[e]); 
				}
			}
		}
		answer = max(answer, dp[i][0] - (C *(i*i)));
	}
	cout << answer << "\n";
	return 0;
}