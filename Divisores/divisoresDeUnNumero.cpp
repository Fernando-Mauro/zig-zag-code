// https://omegaup.com/arena/problem/Cantidad-de-factores-primos/
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   while(true){
      int n;
      cin >> n;
      for(int i = 1; i <= n; ++i){
         if(n % i == 0){
            cout << i << " ";
         }
      }
      cout << endl;
   }
   return 0;
}