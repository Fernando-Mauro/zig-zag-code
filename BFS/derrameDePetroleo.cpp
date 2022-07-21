/*
  https://omegaup.com/arena/problem/COMI-Derrame-de-Petroleo/
  
  Solucion:
  Utilizar BFS para simular el movimiento del petroleo sobre el oceano. Correr la BFS mientras el nivel
  del BFS sea menor a los días que tenemos que hacer la simulación.
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector <vector<char>> matriz;

struct casilla{
   int x;
   int y;
   int dias;
};

vector<int> changeRows = { -1, 0, 1, 0 };
vector<int> changeColumns = { 0, 1, 0, -1 };

void bfs(matriz &oceano, int i, int j, int dias){
   queue <casilla> cola;
   casilla inicial = {i,j,1};
   cola.push(inicial);
   while(!cola.empty()){
      casilla actual = cola.front();
      cola.pop();
      if(actual.dias > dias) continue;
      for(int k = 0; k < 4; ++k){
         int newx = actual.x + changeRows[k];
         int newy = actual.y + changeColumns[k];
         bool inRange = newx >= 0 && newy >= 0 && newx < oceano.size() && newy < oceano[0].size();
         if(inRange && oceano[newx][newy] == '.' ){
            casilla vecino = {newx, newy, actual.dias + 1};
            cola.push(vecino);
            oceano[newx][newy] = '*';
         }
      }
   }
}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int filas, columnas, dias;
   cin >> filas >> columnas >> dias;
   matriz oceano(filas, vector <char> (columnas));
   for(int i = 0; i < filas; ++i){
      for(int j = 0; j < columnas; ++j){
         cin >> oceano[i][j];
      }
   }
   for(int i = 0; i < filas; ++i){
      for(int j = 0; j < columnas; ++j){
         if(oceano[i][j] == '$'){
            bfs(oceano, i,j, dias);
            break;
         }
      }
   }
   for(int i = 0; i < filas; ++i){
      for(int j = 0; j < columnas; ++j){
         cout << oceano[i][j];
      }
      cout << endl;
   }
   return 0;
}