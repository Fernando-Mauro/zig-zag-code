// https://omegaup.com/arena/problem/moscas
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   vector <int> moscas(60000);
   int n;
   cin >> n;
   int inicio, final, maximaMuerte = 0, maximaVida = 0;
   while(n--){
      cin >> inicio >> final;
      while(inicio <= final){
         moscas[inicio]++;
         maximaMuerte = max(maximaMuerte, inicio);
         maximaVida = max(maximaVida, moscas[inicio]);
         inicio++;
      }
   }
   cout << maximaVida << endl;
   int inicioRango, finalRango;
   for(int i = 0; i <= maximaMuerte; ++i){ 
      if(moscas[i] == maximaVida){
         inicioRango = i, finalRango = i;
         ++i;
         while(moscas[i] == maximaVida){
            ++finalRango;
            ++i;
         }
         if(inicioRango != finalRango){
            cout << inicioRango << " " << finalRango << endl;
         }
      }
   }
   return 0;
}