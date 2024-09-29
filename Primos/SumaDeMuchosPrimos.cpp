// https://omegaup.com/arena/problem/suma-muchos-p 
#include <bits/stdc++.h> 

using namespace std;
#define MAX 10000
bitset <MAX> criba;
vector <int> primos;

void rellenarCriba(){
   criba.set();
   criba.reset(0);
   primos.push_back(1);
   for(int i = 2; i < MAX; ++i){
      if(criba[i]){
         primos.push_back(i);
         for(int j = i * 2; j < MAX; j += i){
            criba.reset(j);
         }
      }
   }
}

int main(){
   int numero;

   cin >> numero;
   rellenarCriba();
 
   for(int i = primos.size() - 1; i >= 0; --i){
      
      if(primos[i] <= numero){
         numero -= primos[i];

         cout << primos[i] << " ";
      }

   }
   return 0;
}