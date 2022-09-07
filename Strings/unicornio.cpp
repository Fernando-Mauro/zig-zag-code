// https://omegaup.com/arena/problem/Unicornio/
#include <bits/stdc++.h>

using namespace std;
/*
                    /
               ,.. /
             ,'   ';
  ,,.__    _,' /';  .
 :','  ~~~~    '. '~
:' (   )         )::,
'. '. .=----=..-~  .;'
 '  ;'  ::   ':.  '"
   (:   ':    ;)
    \\   '"  ./
     '"      '"
Un unicornio para entrar en contexto :)
*/
string unicornio = "unicornio";

void comprobar(string &cadena){
   if(cadena.size() < 9) {
      int resultado = cadena.size() - 9;
      cout << resultado;
      return;
   }
   for(int i = 0; i < unicornio.size(); ++i){
      if(unicornio[i] != tolower(cadena[i])){
         cout << cadena[i]; 
         return;
      }
   }
   cout << 0;
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   string cadena;
   cin >> cadena;
   comprobar(cadena);
   return 0;
}