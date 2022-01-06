#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

vector <int> numeros;
void criba(){
   bitset <MAX> primos;
   primos.set();
   for(int i = 2; i <= MAX; ++i){
      if(primos[i]){
         numeros.push_back(i);
         for(int j = i * 2; j <= MAX; j += i){
            primos.reset(j);
         }
      }
   }
}
int main(){
   criba();
}