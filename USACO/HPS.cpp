#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) (x).size()

const int MAXN = 1e5 + 2;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

long long int N, K;
long long int dp[MAXN][25][5], G[MAXN];

int main(){
	setIO("hps");
	cin >> N >> K;
	for(int i = 1; i <= N; ++i){
		char a;
		cin >> a;
		if(a == 'H'){
			G[i] = 1;
		}
		else if(a == 'P'){
			G[i] = 2;
		}
		else if(a == 'S'){
			G[i] = 3;
		}
	}
	for(int i = 1; i <= N; ++i){
		for(int j = 0; j <= K; ++j){
			for(int h = 1; h <= 3; ++h){
				if(h == G[i])dp[i][j][h]++;
				dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][h]);
				dp[i+1][j+1][2] = max(dp[i+1][j+1][2], dp[i][j][h]);
				dp[i+1][j+1][3] = max(dp[i+1][j+1][3], dp[i][j][h]);
				dp[i+1][j][h] = max(dp[i+1][j][h], dp[i][j][h]);
			}
		}
	}
	cout << max(dp[N][K][1], max(dp[N][K][2], dp[N][K][3])) << "\n";
	return 0;
}