#include <bits/stdc++.h>

#define MOD 4

using namespace std;

struct Node{
  int x, y, times = 0;
  friend bool operator==(Node a, Node b){
    return a.x == b.x && a.y == b.y;   
  }
}in, ac, fin, sig;

int n, m;
int mp[1001][1001];
bool vis[1001][1001][6];
queue<Node> q;
vector<int> f = {0,-1,0,1,0};
vector<int> c = {0,0,1,0,-1};

int alda(){
  q.push(in);
  while(!q.empty()){
    ac = q.front();
    q.pop();
    if(ac == fin)return ac.times;
    for(int i = 0; i < 5; ++i){
      sig.x = ac.x + f[i];
      sig.y = ac.y + c[i];
      sig.times = ac.times + 1;
      if(sig.x >= 0 && sig.y >= 0 && sig.x < n && sig.y < m){
        if(mp[sig.x][sig.y] == 0 || sig.times % mp[sig.x][sig.y] != 0){
          if(!vis[sig.x][sig.y][sig.times % MOD]){
            vis[sig.x][sig.y][sig.times % MOD] = 1;
            q.push(sig);
          }
        }
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> in.y >> in.x >> fin.y >> fin.x;
  in.x--, in.y--, fin.x--, fin.y--;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      mp[i][j] = c - '0';
    }
  }
  cout << alda() << "\n";
  return 0;
}
