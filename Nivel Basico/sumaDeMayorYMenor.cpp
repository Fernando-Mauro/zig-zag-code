// https://omegaup.com/arena/problem/Suma-de-mayor-y-menor/
#include <iostream>
#include <vector>
#include <algorithm>
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
   cout << numeros[0] + numeros[numeros.size() - 1];
   return 0;
}