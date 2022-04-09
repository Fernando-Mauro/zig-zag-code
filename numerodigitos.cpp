#include <bits/stdc++.h>

using namespace std;

int main(){
   long long int numero = 0;
   long long int total= 0;
   cin >> numero;
   for(long long int i = 1; i <= numero; i++){
      if(i < 10){
         total++;
         continue;
      }else if(i >= 10 && i < 100){
         total += 2;
         continue;
      }else if(i >= 100 && i < 1000){
         total += 3;
         continue;
      }else if(i >= 1000 && i <10000){
         total += 4;
         continue;

      }else if(i >= 10000 && i <100000){
         total += 5;
         continue;

      }else if(i >= 100000 && i <1000000){
         total += 6;
         continue;

      }else if(i >= 1000000 && i <10000000){
         total += 7;
         continue;

      }else if(i >= 10000000 && i <100000000){
         total += 8;
         continue;
      }

   }
   cout << total << endl;
   return 0;
}