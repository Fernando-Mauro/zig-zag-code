#include <bits/stdc++.h>

using namespace std;

int funcion(int n, int m){
   if(n == 5){
      return funcion(n - 2,  m - 2) * 2;
   }
   if(n < 5){
      return 20;
   }
   if(n > 5){
      return funcion(n - 1, m - 1 ) + 2;
   }
}
int main(){
   int n, m;
   cin >> n >> m;
   cout << funcion(n, m);
}