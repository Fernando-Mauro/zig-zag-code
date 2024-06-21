#include <bits/stdc++.h>


using namespace std;

typedef vector <vector <char>> matriz; 

int main() {

    int m, n;
    cin >> m >> n;

    matriz mapa(m, vector <char> (n));

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> mapa[i][j];
        }
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(mapa[i][j] == '*')
                cout << i + 1 << " " << j + 1 << "\n";
        }
    }

  return 0;
}