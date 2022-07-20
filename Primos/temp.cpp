// https://omegaup.com/arena/problem/ndivisores
#include <bits/stdc++.h>

using namespace std;
#define MAX 100000
typedef unsigned long long int ulli;
bitset <MAX> criba;
vector <ulli> primos;

void rellenarCriba(){
   criba.set();
   criba.reset(0);
   criba.reset(1);
   for(int i = 2; i < MAX; i++){
      if(criba[i]){
         primos.push_back(i);
         for(int j = i * 2; j < MAX; j += i){
            criba.reset(j);
         }
      }
   }
}
ulli divisores(ulli number){
   int divisores = 1;
   long long int raiz = sqrt(number);
   for(int i = 0; i < primos.size() && primos[i] <= number; ++i){
      int vecesPrimo = 1;
      while(number % primos[i] == 0){
         vecesPrimo++;
         number /= primos[i];
      }
      divisores *= vecesPrimo;
   }
   if(number != 1){
      divisores *= 2;
   }
   return divisores;
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   rellenarCriba();
   int n;
   cin >> n;
   int i = 2;
   while(true){
      if(divisores(i) == n){
         cout << i << endl;
         break;
      }
      i++;
   }
   return 0;
}