#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   vector <int> numeros(n);
   for(int i = 0; i < n; i++){
      cin >> numeros[i];
   }
   sort(numeros.begin(), numeros.end());
   for(int i = 0; i < n; i++){
      cout << numeros[i] << " ";
   }
   return 0;
}