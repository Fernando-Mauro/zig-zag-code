#include <bits/stdc++.h>

using namespace std;

struct Node {
    int weight;
    bool black;
};

struct Cord {
    int x;
    int y;
};

typedef vector <vector <Node>> matriz;

vector neighbordsX = {1, 0 , -1, 0};
vector neighbordsY = {0, 1, 0, -1};

void bfs(matriz &mapa, int i, int j){
    queue <Cord> adj;
    vector <vector <bool>> visited(mapa.size(), vector <bool> (mapa[0].size(), false));
    Cord start = {i, j};
    adj.push(start);

    while(!adj.empty()){
        Cord current = adj.front();
        adj.pop();
        visited[current.x][current.y] = true;
        for(int i = 0; i < 4; ++i){
            Cord next = {current.x + neighbordsX[i], current.y + neighbordsY[i]};

            if(next.x >= 0 && next.y >= 0 && next.x < mapa.size() && next.y < mapa[0].size()){
                
            }
        }
    }   
}

int main(){
    int n, m;
    cin >> n >> m;

    matriz mapa(n, vector <Node> (m));

    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> mapa[i][j].weight;
        }
    }


    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> mapa[i][j].black;
        }
    }

    // deploy bfs from each node

    
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            bfs(mapa, i, j);
        }
    }
    return 0;
}