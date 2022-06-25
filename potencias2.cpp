// https://omegaup.com/arena/problem/ptwo
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int i64;
i64 potencia(i64 base, i64 exponente){
   if(exponente == 0){
      return 1;
   }
   if(exponente == 1){
      return base;
   }
   if(exponente % 2 == 0){
      i64 resultado =  potencia(base, exponente / 2);
      return resultado * resultado;
   }else{
      return potencia(base, exponente - 1) * base;
   }
}
int main(){
   i64 exponente;
   cin >> exponente;
   i64 result = potencia(2,exponente);
   cout  <<  result;
}