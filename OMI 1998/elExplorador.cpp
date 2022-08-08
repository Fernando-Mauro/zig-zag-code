// https://omegaup.com/arena/problem/OIEG2013SSC
#include <bits/stdc++.h>

using namespace std;

struct coordenada{
   int x;
   int y;
   int distancia = 0;
};

vector <int> cambiarFilas = { -1, 0, 1, 0};
vector <int> cambiarColumnas = {0, 1, 0, -1};

int BFS(coordenada coordInicial, vector <vector <char>> &mapa){
   queue <coordenada> cola;
   cola.push(coordInicial);
   while(!cola.empty()){
      coordenada nodo = cola.front();
      cola.pop();
      for(int i = 0; i < 4; ++i){
         coordenada vecino = {nodo.x + cambiarFilas[i], nodo.y + cambiarColumnas[i], nodo.distancia + 1};
         bool inRange = vecino.x >= 0 && vecino.y >=0 && vecino.x < mapa.size() && vecino.y < mapa[0].size();
         if(inRange && mapa[vecino.x][vecino.y] != '1' ){
            if(mapa[vecino.x][vecino.y] == '*'){
               return nodo.distancia + 1;
            }else{
               mapa[vecino.x][vecino.y] = '1';
               cola.push(vecino);
            }
         }
      }
   }
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n, m;
   cin >> n >> m;
   vector <vector <char>> mapa(n, vector <char> (m));
   for(int i = 0; i < n; ++i){ 
      for(int j = 0; j < m; ++j){ 
         cin >> mapa[i][j];
      }
   }
   coordenada puntoA;
   cin >> puntoA.x >> puntoA.y;
   coordenada puntoB;
   cin >> puntoB.x >> puntoB.y;
   mapa[puntoB.x][puntoB.y] = '*';
   cout << BFS(puntoA, mapa) + 1;
   return 0;
}