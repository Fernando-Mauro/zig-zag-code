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
      if(cadena[i] != ' '){
         if(bandera){
            cout << char(toupper(cadena[i]));
         }else{
            cout << cadena[i];
         }
         bandera = !bandera;
      }else{
         cout << cadena[i];
      }
   }
   return 0;
}