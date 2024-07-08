#include <bits/stdc++.h> 

using namespace std;

typedef vector <vector <bool>> matrix;


struct Cord{
    int x;
    int y;
    int blocks;
};

Cord start;
Cord exitCord;

vector <int> neighbordsX = {-1, 1, 0, 0};
vector <int> neighbordsY = {0, 0, 1, -1};

int solve(matrix &mapTreasure, matrix &visited){
    
    queue <Cord> bfs;
    bfs.push(start);

    while(!bfs.empty()){
        Cord current = bfs.front();
        bfs.pop();

        for(int i = 0; i < 4; ++i){
            int newX = current.x + neighbordsX[i];
            int newY = current.y + neighbordsY[i];
            
            if(newX >= 0 && newX < mapTreasure.size() && newY >= 0 && newY < mapTreasure[0].size() && !visited[newX][newY] && !mapTreasure[newX][newY]){
                if(newX == exitCord.x && newY == exitCord.y)
                    return current.blocks + 1;
                Cord newNeighbord = {newX, newY, current.blocks + 1};
                visited[newX][newY] = true;
                bfs.push(newNeighbord);
            }
        }
    }
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;
    matrix mapTreasure(n, vector <bool> (m, false));
    matrix visited(n, vector <bool> (m, false));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int aux;
            cin >> aux;
            mapTreasure[i][j] = aux;
        }
    }

    cin >> start.x >> start.y;
    start.blocks = 1;
    cin >> exitCord.x >> exitCord.y;

    cout << solve(mapTreasure, visited) << "\n";
    return 0;
}