#include <bits/stdc++.h> 

using namespace std;

typedef vector <vector <bool>> matrix;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n , e, time;
    cin >> n >> e >> time;

    matrix adjacencyMatrix (101, vector <bool> (101, false));    

    int first, second;
    while(e--){
        cin >> first >> second;
        adjacencyMatrix[first][second] = true;
        adjacencyMatrix[second][first] = true;
    }
    return 0;
}