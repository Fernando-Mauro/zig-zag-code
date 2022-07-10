#include <iostream>

using namespace std;

typedef long long int i64;

i64 exp (i64 base, i64 exponente, i64 mod){
   //cualquier numero elevado a 0 da 1
   if(exponente == 0){
      return 1;
   }
   //cualquier numero elevado a 1 da el mismo numero
   if(exponente == 1){
      return base;
   }
   //si el numero no es par se hace que sea par
   if(exponente % 2 == 1){
      return (base % mod * exp(base, exponente - 1, mod) % mod) % mod;
   }
   if(exponente % 2 == 0){
      return (exp(base, exponente / 2, mod) % mod * exp(base, exponente / 2, mod) % mod) % mod;
   }
   return 0;
}
int main(){
   i64 base, exponente, mod;
   cin >> base >> exponente >> mod;
   cout << exp(base, exponente, mod) << endl;
   return 0;
}