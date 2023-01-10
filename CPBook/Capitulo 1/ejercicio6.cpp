#include <bits/stdc++.h>

using namespace std;

int main(){
   // cin.tie(nullptr);
   // ios_base::sync_with_stdio(false);
   int n;
   scanf("%d", &n);
   vector <int> numeros (n);
   for(int i = 0; i < n; ++i) scanf("%d", &numeros[i]);
   int buscar; cin >> buscar;
   (binary_search(numeros.begin(), numeros.end(), buscar)) ? printf("Existe\n") : printf("No existe\n");
   return 0;
}