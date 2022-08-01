// https://omegaup.com/arena/problem/Incrementando-pares-en-interval2
#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;
   vector <int> numeros(n);
   vector <int> barrido(n,0);
   for(int i = 0; i < n; ++i){
      cin >> numeros[i];
   }
   int m;
   int inicioIntervalo, finalIntervalo;
   cin >> m;
   while(m--){
      cin >> inicioIntervalo >> finalIntervalo;
      for(int i = inicioIntervalo; i <= finalIntervalo; ++i){ 
         if(!(numeros[i] & 1)){
            barrido[i] = 1;
         }
      }
   }
   for(int i = 0; i < n; ++i){ 
      cout << numeros[i] + barrido[i] << " ";
   }
}