#include <bits/stdc++.h>

using namespace std;

int funcion(int n){
   if(n <= 5){
      return 1;
   }else{
      return funcion(n - 2) * 5;
   }
}

int main(){
   int n;
   cin >> n;
   cout << funcion(n);
}