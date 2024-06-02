#include <bits/stdc++.h> 


using namespace std;

typedef vector <vector <int>> matriz;
typedef vector <vector <bool>> matrizBool;


matrizBool last;

struct Coord{
    int x;
    int y;
};

bool isSubMatriz(matriz &original, matriz &subMatriz, int row, int col) {
    int n = subMatriz.size();
    int m = subMatriz[0].size();
    vector <Coord> incidences;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (original[row + i][col + j] != subMatriz[i][j]) {
                return false;
            }
            incidences.push_back({row + i, row + j});
        }
    }

    for(int i = 0; i < incidences.size(); ++i){
        last[incidences[i].x][incidences[i].y] = true;
    }

    return true;
}

void solve(matriz &original, matriz &subMatriz) {

    for (int i = 0; i < original.size(); i++) {
        for (int j = 0; j < original[i].size(); j++) {
            if (i <= (original.size() - subMatriz.size()) && j <= (original[0].size() - subMatriz[0].size())) {
                isSubMatriz(original, subMatriz, i, j);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    matriz original(n, vector <int> (m));
    last.resize(n, vector <bool> (m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> original[i][j];
        }
    }    
    
    cin >> n >> m;
    matriz submatriz (n, vector <int> (m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> submatriz[i][j];        
        }
    }    

    solve(original, submatriz);

    for(int i = 0; i < last.size(); ++i){
        for(int j = 0; j < last[0].size(); ++j){
            cout << last[i][j] << " ";       
        }
        cout << "\n";
    }
    
    return 0;
}