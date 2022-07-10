#include <bits/stdc++.h>

using namespace std;

int funcion(int n){
   if(n <= 20){
      return 1;
   }else{
      return funcion(n-5) + 5 + n;
   }
}
int main(){
   int n;
   cin >> n;
   cout << funcion(n);
}