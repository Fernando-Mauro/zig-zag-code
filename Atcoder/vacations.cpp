#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 2;

int N;
long long dp[MAXN][4];
long long A[MAXN], B[MAXN], C[MAXN];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 1; i <= N; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		A[i] = a, B[i] = b, C[i] = c;
	}
	dp[1][1] = A[1];
	dp[1][2] = B[1];
	dp[1][3] = C[1];
	for(int i = 2; i <= N; ++i){
		dp[i][1] += max(dp[i-1][2], dp[i-1][3] + A[i]);
		dp[i][2] += max(dp[i-1][1], dp[i-1][3] + B[i]);
		dp[i][3] += max(dp[i-1][1], dp[i-1][2] + C[i]);
	} 
	cout << max(dp[N][1],max(dp[N][2], dp[N][3])) << "\n";
	return 0;
}
