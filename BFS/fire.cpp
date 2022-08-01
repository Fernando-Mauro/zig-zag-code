// https://omegaup.com/arena/problem/fire
#include <bits/stdc++.h>

using namespace std;

typedef vector <vector <int>> matriz;

vector <int> cambiarColumna = {0,1,0,-1};
vector <int> cambiarFila = {-1,0,1,0};

void expandir(matriz &mapa,vector <vector <char>> &resultado, int xActual, int yActual, int minutos, int d ){
   
   if(minutos < 0) return;

   if(mapa[xActual][yActual] <= minutos){
   
      resultado[xActual][yActual] = '.';
   
      minutos -= mapa[xActual][yActual];

      for(int i = 0; i < 4; ++i){ 
         int newY =  cambiarFila[i] + yActual;
         int newX = cambiarColumna[i] + xActual ;
         bool inRange = newX >= 0 && newY >= 0 && newX < mapa.size() && newY < mapa[0].size();
         if(inRange){
            // resultado[newX][newY] = '*';
            expandir(mapa, resultado, newX, newY, minutos, 1);
         }
      }
   }else{
      if(resultado[xActual][yActual] != '.'){
         resultado[xActual][yActual] = '*';
      }
   }
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n, m;
   cin >> n >> m;
   int minutos = 0;
   cin >> minutos;
   matriz mapa(n, vector <int> (m));
   vector <vector <char>> resultado(n, vector <char> (m));
   string aux;
   for(int i = 0; i < n; ++i){ 
      for(int j = 0; j < m; ++j){
         cin >> resultado[i][j];
         mapa[i][j] = resultado[i][j] - '0';
      }
   }

   expandir(mapa,resultado, 0,0,minutos,0);

   for(int i = 0; i < n; ++i){ 
      for(int j = 0; j < m; ++j){ 
         cout << resultado[i][j] << " ";
      }
      cout << endl;
   }

   return 0;
}