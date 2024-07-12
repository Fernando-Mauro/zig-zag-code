#include <bits/stdc++.h> 

using namespace std;

struct Enemy{
    int tamanio;
    bool dead = false;

    bool operator<(Enemy a){
        return this->tamanio < a.tamanio;
    }
};

bool customLowerBound(Enemy a, const int tamanio){
    return a.tamanio < tamanio && !a.dead;
}

// int buscarMenorEl(vector <Enemy> &enemigos, int mayorSoldado){
//     for(int i = enemigos.size() - 1; i >= 0; i--){
//         if(enemigos[i].tamanio < mayorSoldado && !enemigos[i].dead)
//             return i;
//     }
//     return -1;
// }

int buscarMayorIgualEl(vector <Enemy> &enemigos, int mayorSoldado){
    auto iterator = lower_bound(enemigos.begin(), enemigos.end(), mayorSoldado, customLowerBound);

    // Si no se encontró
    if(iterator != enemigos.end()){
        // -> inicio, 0
        // -> end = n
        return distance(enemigos.begin(), iterator);
    }

    return -1;
}

int solve(vector <int> &aliados, vector <Enemy> &enemigos){
    
    int suma = 0;
    sort(aliados.begin(), aliados.end());
    sort(enemigos.begin(), enemigos.end());

    for(int i = aliados.size() - 1; i >= 0; i--){
        int mayorSoldado = aliados[i];
        int posMenorEl = buscarMayorIgualEl(enemigos, mayorSoldado);
        
        if( enemigos[posMenorEl].tamanio == aliados[i]){
            suma += mayorSoldado;
            enemigos[posMenorEl].dead = true;
        }else{
            enemigos[posMenorEl].dead = true;
        }
    }
    return suma;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> aliados(n);
    vector <Enemy> enemigos(n);

    for(int i = 0; i < n; ++i){
        cin >> aliados[i];
    }

    for(int j = 0; j < n; ++j){
        cin >> enemigos[j].tamanio;
    }

    cout << solve(aliados, enemigos) << "\n";

    return 0;
}