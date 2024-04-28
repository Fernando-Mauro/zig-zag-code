#include <bits/stdc++.h> 


using namespace std;
typedef vector <vector <char>> matriz;


int neighbordsX[] = {-1, 0, 0, 1};
int neighbordsY[] = {0, -1, 1, 0};

vector <vector <int>> memoCoords(0,vector <int> (4));

struct Node{
    int x, y;
};

vector <int> bfs(matriz &mapa, int x, int y){
    queue <Node> nodesVisit;
    Node firstNode = {x, y};
    nodesVisit.push(firstNode);

    int maxX = x;
    int maxY = y;

    int minX = x;
    int minY = y;

    while(!nodesVisit.empty()){
        Node currentNode = nodesVisit.front();
        nodesVisit.pop();

        for(int i = 0; i < 4; ++i){
            int newI = currentNode.x + neighbordsX[i];
            int newJ = currentNode.y + neighbordsY[i];
            
            if(newI >= mapa.size() || newJ >= mapa[0].size() || newI < 0 || newJ < 0 || mapa[newI][newJ] == '*' || mapa[newI][newJ] != '1')
                continue;
            
            mapa[newI][newJ] = '*';

            Node nextNode = {newI, newJ};

            nodesVisit.push(nextNode);

            maxX = max(maxX, newI);
            maxY = max(maxY, newJ);

            minX = min(minX, newI);
            minY = min(minY, newJ);
        }
    }

    return {maxX, maxY, minX, minY};
}

void refillMap(matriz &copy, int maxX, int maxY, int minX, int minY){
    for(int i = minX; i <= maxX; ++i){
        for(int j = minY; j <= maxY; ++j){
            copy[i][j] = '1';
        }
    }
}


void solve(matriz &mapa, matriz &copy) {
    for(int i = 0; i < mapa.size(); i++){
        for(int j = 0; j < mapa[i].size(); j++){
            
            if(mapa[i][j] == '1'){
                auto maxCoords = bfs(mapa, i, j);
                refillMap(copy, maxCoords[0], maxCoords[1], maxCoords[2], maxCoords[3]);
                
                memoCoords.push_back({maxCoords[2], maxCoords[3], maxCoords[0], maxCoords[1]});
            }

        }
    }
}

void checkCollisions(matriz &copy){
    for(int i = 0; i < memoCoords.size(); ++i){
        for(int j = 0; j < memoCoords.size(); ++j){
            if(i != j){
                // 
                if(abs(memoCoords[i][0] - memoCoords[j][2]) <= 1 || abs(memoCoords[i][2] - memoCoords[j][3]) <= 1 || abs(memoCoords[i][2] - memoCoords[j][0]) <= 1 || abs(memoCoords[i][3] - memoCoords[j][4]) <= 1){
                    int maxX = -1;
                    int minX = INT_MAX;
                    for(int x = 0; x <= 2; x += 2){
                        maxX = max(memoCoords[i][x], maxX);
                        maxX = max(memoCoords[j][x], maxX);

                        minX = min(memoCoords[i][x], minX);                    
                        minX = min(memoCoords[j][x], minX);                    
                    }

                    int maxY = -1;
                    int minY = INT_MAX;
                    for(int x = 1; x <3; x += 2){
                        maxY = max(memoCoords[i][x], maxY);
                        maxY = max(memoCoords[j][x], maxY);
                        minY = min(memoCoords[i][x], minY);                    
                        minY = min(memoCoords[j][x], minY);                    
                    }
                    refillMap(copy, maxX, maxY, minX, minY);
                    // cout << maxX << " " << maxY << " " << minX << " " << minY<< endl;
                }
            }    
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    matriz mapa (n, vector <char> (m));

    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mapa[i][j];
        }
    }

    matriz copy(n , vector<char> (m));
    matriz final(n , vector<char> (m));
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            copy[i][j] = mapa[i][j];
            final[i][j] = mapa[i][j]; 
        }
    }

    solve(mapa, copy);
    // checkCollisions(copy);
    solve(copy, final);

    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << final[i][j];
        }
        cout << endl;
    }

    return 0;
}