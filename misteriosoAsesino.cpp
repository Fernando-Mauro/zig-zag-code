#include <bits/stdc++.h>

using namespace std;

int main(){
   int largo, ancho, lugaresAlacran;
   cin >> largo >> ancho >> lugaresAlacran;
   vector<vector<bool>>cuarto(largo, vector <bool> (ancho, false));
   int x,y;
   while(lugaresAlacran--){
      cin >> x >> y;
      cuarto[x - 1][y - 1] = true;
   }
   int contador = 0;
   for(int i = 0; i < (cuarto.size() - 1); i++){
      for(int j = 0; j < (cuarto[i].size() - 1); j++){
         if(!cuarto[i][j] && !cuarto[i + 1][j] && !cuarto[i][j + 1] && !cuarto[i+1][j+1]) contador++;
      }
   }
   cout << contador;
}  