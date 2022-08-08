// https://omegaup.com/arena/problem/OIEG2013SSA
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int A,B,N;
   cin >> A >> B >> N;
   int numero = 1, temp;
   int pasos = 0;
   while(numero != N){
      temp = numero;
      numero *= A;
      ++pasos;
      if(numero > 9999){
         numero = 1;
      }
      if(numero == N){
         break;
      }
      temp /= B;
      ++pasos;
      if(temp == N){
         break;
      }
      numero = temp;
   }
   cout << pasos << endl;
   return 0;
}