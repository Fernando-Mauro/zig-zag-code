#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

struct nodo{
    int x, w;
    friend bool operator<(nodo a, nodo b) {
    return a.w < b.w;
  }
};

int T;

vector<int> dijkstra(int origen, vector<vector<nodo>> &adj, int c){
    vector<int> distancia(c, INT32_MAX);
    distancia[origen] = 0;
    priority_queue<nodo> pq;
    pq.push({origen, 0});
    while(!pq.empty()){
        int u = pq.top().x;
        pq.pop();
        for(auto e: adj[u]){
            int v = e.x;
            int we = e.w;
            if(distancia[u] + we < distancia[v]){
                distancia[v] = distancia[u] + we;
                pq.push({v, distancia[v]});
            }
        }
    }
    return distancia;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        int V, K;
        cin >> V >> K;
        vector<vector<nodo>> adj(MAXN);
        for(int i = 0; i < K; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
        }
        int A, B;
        cin >> A >> B;
        auto dist = dijkstra(A, adj, V+2);
        if(dist[B] == INT32_MAX)cout << "NO\n";
        else cout << dist[B] << "\n";
    }
    return 0;
}