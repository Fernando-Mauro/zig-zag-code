#include <bits/stdc++.h> 

using namespace std;

typedef long long int i64;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, x, y, colonias;
    cin >> n >> x >> y >> colonias;

    int coloniasInfectadas = 0;

    // Arriba, abajo, izquierda, derecha
    vector <int> distancias(4);
    distancias[0] = x;
    distancias[1] = (n - x) + 1;
    distancias[2] = (n - y) + 1;
    distancias[3] = y;
    
    vector <int> diasParaColapsar(4);
    // Arriba -> Derecha 
    // Arriba -> Izquierda
    // Abajo -> Derecha
    // Abajo -> Izquierda
    diasParaColapsar[0] = distancias[0] + distancias[3];
    diasParaColapsar[1] = distancias[0] + distancias[2];
    diasParaColapsar[2] = distancias[1] + distancias[3];
    diasParaColapsar[3] = distancias[1] + distancias[2];
    
    for(int i = 0;; i++){
        i64 infectadasI = ceil(pow(((i + 1) * 2 - 1), 2) / 2);
        
        i64 fuera = 0; 
        // Por cada lado comprobar que no me haya salido, si me sali, restar lo que me sale a lo que ya infecté
        for(int j = 0; j < 4; ++j){
            if(distancias[j] <= i){
                fuera += pow(((i - distancias[j]) + 1), 2);
            }
        }
        
        //Los que estan colapsados contrarrestarlos
        for(int j = 0; j < 4; ++j){
            if(diasParaColapsar[j] <= i){
                int n = (i - diasParaColapsar[j]) + 1;
                fuera -= (n * (n + 1) / 2);
            }
        }

        infectadasI -= fuera;
        
        coloniasInfectadas = infectadasI;

        if(infectadasI >= colonias){
            cout << i << endl;
            break;
        }
    }

    return 0;
}