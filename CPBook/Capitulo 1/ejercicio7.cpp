#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n = 10;
   vector <int> numeros(n);
   for(int i = 0 ; i < n; ++i) numeros[i] = i;
   
   do{
      for(int i = 0; i < n; ++i) printf("%c", 'A' + numeros[i]);
      printf("\n");
   }while(next_permutation(numeros.begin(), numeros.end()));
   return 0;
}