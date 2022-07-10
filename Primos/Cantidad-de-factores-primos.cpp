// https://omegaup.com/arena/problem/Cantidad-de-factores-primos
#include <bits/stdc++.h>

using namespace std;

int divisores(int n){
   int total = 0;
   for(int i = 1; i <= sqrt(n); ++i){
      if(n % i == 0){
         int divisor = n / i;
         // cout << "Divisor: " << divisor << " dividendo:" << i << endl;
         if(divisor == i){
            total++;
         }else{
            total += 2;
         }
      }
   }
   return total;
}
int main(){
   int n;
   cin >> n;   
   vector <int> numbers(n);
   int maximo = -100;
   for(int i = 0; i < n; i++){ 
      cin >> numbers[i];
      cout << divisores(numbers[i]) << endl;
   }
   
   return 0;
}