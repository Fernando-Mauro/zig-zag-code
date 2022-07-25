// https://omegaup.com/arena/problem/El-problema-de-3n1
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int inicio, fin;
   int mayor = -1;
   cin >> inicio >> fin;
   for(int i = inicio; i <= fin; ++i){ 
      int aux = i;
      int pasos = 1;
      while(aux != 1){
         if(aux % 2 == 0){
            aux /= 2;
            ++pasos;
         }else{
            aux *= 3;
            ++aux;
            ++pasos;
         }
      }
      if (pasos > mayor){
         mayor = pasos;
      }
   }
   cout << mayor;
   return 0;
}