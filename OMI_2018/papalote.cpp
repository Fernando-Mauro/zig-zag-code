#include <bits/stdc++.h> 

using namespace std;

set <int> fixedRows;
set <int> fixedCols;


void invertRows(){

}
void fixRows(vector <pair <int, int>> &presumsRow){
    for(int i = 0; i < presumsRow.size(); ++i){
        int sum = presumsRow[i].first + presumsRow[i].second;
        if(!sum){
            // invert values
            presumsRow[i].first *= -1;
            presumsRow[i].second *= -1;
        }
        
    }
}

void solve(vector <vector <int>> &numbers, vector <pair <int, int>> &presumsRow, vector <pair <int, int>> &presumsCol){
    fixRows(presumsRow);
}
int main(){
    int n, m;

    cin >> n >> m;
    
    vector <vector <int>> numbers(n, vector <int> (m));
    vector <pair <int, int>> presumsRow(n);
    vector <pair <int, int>> presumsCol(m);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            cin >> numbers[i][j];
            if(numbers[i][j])
                presumsRow[i].first += numbers[i][j];
            else
                presumsRow[i].second += numbers[i][j];
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(numbers[j][i])
                presumsCol[i].first += numbers[j][i];
            else
                presumsCol[i].second += numbers[j][i];
        }        
    }

    solve(numbers, presumsRow, presumsCol);

    return 0;
}