// https://omegaup.com/arena/problem/camelCase-transformation/
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   bool bandera = true;
   string cadena;
   getline(cin, cadena);
   for(int i = 0; i < cadena.size(); ++i){
      if(cadena[i] >= 65 && cadena[i] <= 122){
         bandera = !bandera;
         (bandera) ? cout << char(tolower(cadena[i])) : cout << char(toupper(cadena[i]));
      }else{
         cout << cadena[i];
      }
   }
   return 0;
}