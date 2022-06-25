#include <bits/stdc++.h>

using namespace std;

int funcion(int n, int m){
   if(n == 1){
      return -1 * funcion(n - 2, m);
   }
   if(n > 3){
      return 2 + funcion(n - 1, m);
   }
   if(n == 2){
      return 2 * m;
   }
   return 0;
}

int main(){
   int n, m;
   cin >> n >> m;
   cout << funcion(n,m);
}