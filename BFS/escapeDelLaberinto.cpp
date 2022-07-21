// https://omegaup.com/arena/problem/Escape-del-laberinto/
#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> coordenadas;

vector<int> changeFilas = { -1, 0, 1, 0 };

vector<int> changeColumnas = { 0, 1, 0, -1 };

bool bandera = false;
// y -> first
// x -> second 
bool DFS(vector <vector<char>> &laberinto, coordenadas actual){
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
         if(laberinto[nuevasCoordenadas.first][nuevasCoordenadas.second] != '#'){
            if(laberinto[nuevasCoordenadas.first][nuevasCoordenadas.second] == 'S'){
               bandera = true;
               break;
            }
            if(laberinto[nuevasCoordenadas.first][nuevasCoordenadas.second] == ' '){
               laberinto[nuevasCoordenadas.first][nuevasCoordenadas.second] = '#';
               DFS(laberinto, nuevasCoordenadas);
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
   vector <vector<char>> laberinto(filas, vector <char> (columnas));
   cin.ignore();
   string aux;
   coordenadas entrada;
   for(int i = 0; i < filas; ++i){
      getline(cin, aux);
      for(int j = 0; j < aux.size(); j++){
         laberinto[i][j] = aux[j];
         if(aux[j] == 'E') entrada = {i,j};
      }
   }
   // cout << entrada.first << entrada.second << endl;
   // cout << salida.first << salida.second << endl;
   coordenadas actual = entrada;
   DFS(laberinto, actual);
   if(bandera) cout << "SI" << endl;
   else cout << "NO" << endl;
   return 0;
}