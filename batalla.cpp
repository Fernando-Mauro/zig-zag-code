// #include <bits/stdc++.h>

// using namespace std;

// void buscar(vector <int> &aliados, vector <int> &enemigos, int &total, int mayor_enemigos){
//     sort(enemigos.begin(), enemigos.end());
//     for(int i = aliados.size() - 1; i >= 0; --i){
//         int mayor = 0;
//         for(int j = 0; j < enemigos.size(); ++j){
//             if(enemigos[j] < aliados[i] && enemigos[j] >= enemigos[j]){
//                 mayor = j;
//             }
//         }
//         if(enemigos[mayor] < aliados[i]){
//             total += aliados[i];
//             aliados.erase(aliados.begin() + i);
//             enemigos.erase(enemigos.begin() + mayor);
//         }else{
//             aliados.erase(aliados.begin() + i);
//             enemigos.erase(enemigos.begin() + mayor);
//         }
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//    cin.tie(nullptr);
//   ios_base::sync_with_stdio(false);
//     vector <int> aliados(n);
//     vector <int> enemigos(n);
//     for(int i = 0; i < n; i++){
//         cin >> aliados[i];
//     }
//     int mayor_posicion = 0;
//     for(int i = 0; i < n; i++){
//         cin >> enemigos[i];
//         if(enemigos[i] >= enemigos[mayor_posicion]){
//             mayor_posicion = i;
//         }
//     }
//     sort(aliados.begin(), aliados.end());
//     int total = 0;
//     buscar(aliados, enemigos, total, mayor_posicion);
//     cout << total << endl;
//     return 0;
// }
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