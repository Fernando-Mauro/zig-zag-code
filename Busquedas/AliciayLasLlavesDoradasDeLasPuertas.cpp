// https://omegaup.com/arena/problem/aldp/
#include <bits/stdc++.h>

using namespace std;

int busqueda( int dato, vector <int> &puertas){
   int inicio = 0;
   int final = puertas.size();
   while(inicio <= final){
      int middle  = (inicio + final) / 2;
      if(puertas[middle] == dato) return middle + 1;
      if(puertas[middle] > dato){
         final = middle - 1;
         middle = (inicio + final) / 2;
         continue;
      }
      if(puertas[middle] < dato){
         inicio = middle + 1;
         middle = (inicio + final) / 2;
      }
   }
   return 0;
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n_puertas;
   cin >> n_puertas;
   vector <int> puertas(n_puertas);
   for(int i = 0; i < n_puertas; i++){
      cin >> puertas[i];
   }
   int llaves;
   int buscar;
   cin >> llaves;
   while(llaves--){
      cin >> buscar;
      cout << busqueda(buscar, puertas) << endl;
   }
   return 0;
}