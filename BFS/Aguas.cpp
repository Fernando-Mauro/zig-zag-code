//https://omegaup.com/arena/problem/Aguas-termales/
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char> > Matriz;

vector<int> fils = { -1, 0, 1, 0 };
vector<int> cols = { 0, 1, 0, -1 };
vector<int> fils2 = { -1, -1, 1, 1 };
vector<int> cols2 = { -1, 1, 1, -1 };

long long int size_lago = 0;
void size(int x, int y, Matriz& des) {
    if (des[x][y] == 'A') {
        size_lago++;    
        des[x][y] = 'B';
    }
    for( int i = 0; i < 4; ++i ) {
        int x_i = x + fils[i];
        int y_i = y + cols[i];
        bool sigueDentro = (x_i >= 0 && x_i < des.size() && y_i >= 0 && y_i < des[x_i].size());

        if (sigueDentro && des[x_i][y_i] != 'T' && des[x_i][y_i] == 'A') {
            des[x_i][y_i] = 'B';
            size_lago++;
            size(x_i, y_i, des);
        }
    }
    for( int i = 0; i < 4; ++i ) {
        int x_i = x + fils2[i];
        int y_i = y + cols2[i];
        bool sigueDentro = (x_i >= 0 && x_i < des.size() && y_i >= 0 && y_i < des[x_i].size());

        if (sigueDentro && des[x_i][y_i] != 'T' && des[x_i][y_i] == 'A') {
            des[x_i][y_i] = 'T';
            size_lago++;
            size(x_i, y_i, des);
        }
    }
}        
int main() {
    
    int filas, columnas;
    cin >> filas >> columnas;

    Matriz desastre(filas, vector<char>(columnas, 'T'));

    for ( int i = 0; i < filas; ++i ) {
        for ( int j = 0; j < columnas; ++j ) {
            cin >> desastre[i][j];
        }
    }
    int n, u; cin >> n >> u;
        size(n-1, u-1, desastre);

    cout << "El lago mide " << size_lago << " celdas" << endl;

    return 0;
}