#include <bits/stdc++.h>

using namespace std;


int N, K;
const int MAXN = 50001;
int parent[MAXN], depth[MAXN];
char type[MAXN];

void make_set(int v){
	parent[v] = v;
	depth[v] = 0;
}
int find_set(int v){
	if(parent[v] != v){
		return find_set(parent[v]);
	}
	return v;
}

void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		if(depth[a] < depth[b])
			swap(a, b);
		parent[b] = a;
		if(depth[a] == depth[b])
			depth[a]++;
	}
}

void solve(){
	
	
	int lies = 0;
	cin >> N >> K;

	for(int i = 1; i <= N; ++i){
		make_set(i);
	}
	while(K--){
		int D, X, Y;
		cin >> D >> X >> Y;
		int DX = depth[X], DY = depth[Y];

		if(DX % 3 != 0){
			type[X] = DX % 3 == 1 ? 'A': DX % 3 == 2 ? 'B': 'C'; 
		}
		if(DY % 3 != 0){
			type[Y] = DY % 3 == 1 ? 'A': DY % 3 == 2 ? 'B': 'C';				
		}
		union_set(X, Y);

	}
	for(int i = 1; i <= N; ++i)cout << depth[i] << " ";
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