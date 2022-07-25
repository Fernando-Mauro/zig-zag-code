// https://omegaup.com/arena/problem/Incrementando-pares-en-interval2
#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;
   vector <int> numeros(n);
   vector < pair <int, int *>> pares;
   for(int i = 0; i < n; ++i){
      cin >> numeros[i];
      if(!(numeros[i] & 1)){
         pares.push_back({i, &numeros[i]});
      }
   }
}