// https://omegaup.com/arena/problem/ofmi-2022-subasta/
#include <iostream>

using namespace std;

int main(){
   int n;
   cin >> n;
   int primerValida = 0, segundaValida =0;
   int actual,ultimaValida;
   for(int i = 1; i <= n; i++){
       cin >> actual;
      if(actual >= (primerValida + segundaValida)){
         segundaValida = primerValida;
         primerValida = actual;
         ultimaValida = i;
      }
   }
   cout << ultimaValida;
   return 0;
}