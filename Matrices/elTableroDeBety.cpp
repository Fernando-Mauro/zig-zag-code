#include <bits/stdc++.h> 

using namespace std;

typedef vector <vector <int>> matriz;

int countUp = 0, countDown = 0, countLeft = 0, countRight = 0;

void rotateMatrixRight(matriz &tablero, int positions) {
    int cols = tablero[0].size();
    
    for (int i = 0; i < tablero.size(); ++i) {
        rotate(tablero[i].rbegin(), tablero[i].rbegin() + positions % cols, tablero[i].rend());
    }
}

void rotateMatrixLeft(matriz &tablero, int positions) {
    int cols = tablero[0].size();
    
    for (int i = 0; i < tablero.size(); ++i) {
        rotate(tablero[i].begin(), tablero[i].begin() + positions % cols, tablero[i].end());
    }
}

void moveX(matriz &tablero, int absoluteX){
    
    if(absoluteX > 0){
        rotateMatrixRight(tablero, absoluteX);
    }else{
        rotateMatrixLeft(tablero, abs(absoluteX));
    }
}


void moveY(matriz &tablero, int absoluteY){
    // Arriba positivo
    if(absoluteY > 0){
        rotate(tablero.begin(), tablero.begin() + absoluteY, tablero.end());
    }else{
        rotate(tablero.rbegin(), tablero.rbegin() + abs(absoluteY), tablero.rend());
    }
}

int main(){
    // Derecha positivo
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    matriz tablero(n, vector <int> (m));

    int temp = 0;
    while(k--){
        cin >> temp;
        switch (temp){
            case 1: countUp++; break;
            case 2: countDown++; break;
            case 3: countLeft++; break;
            case 4: countRight++; break;
        }
    }
    int absoluteX = (countRight - countLeft) %  n;
    int absoluteY = (countUp - countDown) % m;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> tablero[i][j];
    
    moveX(tablero, absoluteX);
    moveY(tablero, absoluteY);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}