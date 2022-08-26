// https://omegaup.com/arena/problem/Cuadrados-Pintados-al-reves/
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   vector <int> numeros(n);
   for(int i = 0; i < n; ++i){ 
      cin >> numeros[i];
   }
   for(int i = n -1; i >= 0; --i){ 
      cout << pow(numeros[i],2) << endl;
   }
   return 0;
}