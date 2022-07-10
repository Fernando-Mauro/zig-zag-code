// https://omegaup.com/arena/problem/batalla/
#include <bits/stdc++.h>

using namespace std;

int pelear(vector <int> &aliados, vector <int> &enemigos){
    sort(aliados.begin(), aliados.end());
    sort(enemigos.begin(), enemigos.end());
    int suma = 0;
    for(int j = aliados.size() - 1; j >= 0; --j){
        int aliado_temp = aliados[j];
        pair <int, int> maximoVencedor ={-1,-1};
        pair <int, int> igualdades = { -1, -1};
        pair <int,int> maximoPerdedor = {-1,-1};
        for(int i = 0; i < enemigos.size(); ++i){
            int enemigo_temp = enemigos[i];
            if(enemigo_temp == aliado_temp){
                igualdades.first = aliado_temp;
                igualdades.second = i;
            }
            if(enemigo_temp > aliado_temp && enemigo_temp > maximoPerdedor.first){
                maximoPerdedor.first = enemigo_temp;
                maximoPerdedor.second = i;
            }
            if(aliado_temp > enemigo_temp && enemigo_temp > maximoVencedor.first){
                maximoVencedor.first = enemigo_temp;
                maximoVencedor.second = i;
            }
        }
        if(maximoVencedor.first > maximoPerdedor.first){
            suma += aliado_temp;
            aliados.erase(aliados.begin() + j);
            enemigos.erase( enemigos.begin() + maximoVencedor.second);
            continue;   
        }
        if(maximoPerdedor.first > igualdades.first){
            if(j != 0){
                aliados.erase(aliados.begin() + 0);
                enemigos.erase(enemigos.begin() + maximoPerdedor.second);
            }
        }
        if(igualdades.first == aliado_temp){
            aliados.erase(aliados.begin() + j);
            enemigos.erase(enemigos.begin() + igualdades.second);
        }
    }
    return suma;
}
int main(){
    int n;
    cin >> n;
    vector <int> aliados(n);
    for(int i = 0; i < n; i++){
        cin >> aliados[i];
    }
    vector <int> enemigos(n);
    for(int i = 0; i < n; i++){
        cin >> enemigos[i];
    }
    cout << pelear(aliados, enemigos);
    return 0;
}