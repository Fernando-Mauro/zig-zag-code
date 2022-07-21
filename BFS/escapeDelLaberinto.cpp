// https://omegaup.com/arena/problem/Escape-del-laberinto/
#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> coordenadas;

vector<int> changeFilas = { -1, 0, 1, 0 };

vector<int> changeColumnas = { 0, 1, 0, -1 };

bool bandera = false;
// y -> first
// x -> second 
bool DFS(vector <string> &laberinto, coordenadas actual, vector <vector <bool>> &visitados){
   // explorar hacia arriba, abajo, derecha, izquierda
   if( laberinto[actual.first][actual.second] == 'S'){
      bandera = true;
      return true;
   } 
   coordenadas nuevasCoordenadas;
   for(int i = 0; i < 4; i++){
      // comprobar que estemos dentro de los limites aun
      nuevasCoordenadas.first = actual.first + changeFilas[i];
      nuevasCoordenadas.second = actual.second +  changeColumnas[i];
      if(nuevasCoordenadas.first < laberinto.size() && nuevasCoordenadas.second <laberinto[0].size() && nuevasCoordenadas.first >= 0 && nuevasCoordenadas.second >= 0){
         if(!visitados[nuevasCoordenadas.first][nuevasCoordenadas.second]){
            if(laberinto[nuevasCoordenadas.first][nuevasCoordenadas.second] == 'S'){
               bandera = true;
               break;
            }
            if(laberinto[nuevasCoordenadas.first][nuevasCoordenadas.second] == '#'){
               continue;
            }
            if(laberinto[nuevasCoordenadas.first][nuevasCoordenadas.second] == ' '){
               visitados[nuevasCoordenadas.first][nuevasCoordenadas.second] = true;
               DFS(laberinto, nuevasCoordenadas, visitados);
            }
         }
      }
   }
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int filas, columnas;
   cin >> filas >> columnas;
   vector <string> laberinto(filas);
   vector <vector <bool>> visitados(filas, vector <bool> (columnas, false));
   cin.ignore();
   for(int i = 0; i < filas; ++i){
      getline(cin, laberinto[i]);
   }
   coordenadas entrada;
   coordenadas salida;
   for(int i = 0; i < filas; ++i){
      for(int j = 0; j < columnas; ++j){ 
         if(laberinto[i][j] == 'E') entrada = {i,j};
         if(laberinto[i][j] == 'S') salida = {i,j};
      } 
   }
   // cout << entrada.first << entrada.second << endl;
   // cout << salida.first << salida.second << endl;
   coordenadas actual = entrada;
   DFS(laberinto, actual, visitados);
   if(bandera) cout << "SI" << endl;
   else cout << "NO" << endl;
   return 0;
}