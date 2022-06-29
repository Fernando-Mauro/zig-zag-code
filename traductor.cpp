// https://omegaup.com/arena/problem/COMI-Traductor
#include <bits/stdc++.h>

using namespace std;

int main(){
   map <int, int> diccionario;
   int palabras, palabras_por_traducir;
   cin >> palabras >> palabras_por_traducir;
   int palabra, traduccion;
   while(palabras--){
      cin >> palabra >> traduccion;
      diccionario.insert(pair <int, int> (palabra, traduccion));
   }
   while(palabras_por_traducir--){
      cin >> palabra;
      auto el = diccionario.find(palabra);
      if(el != diccionario.end()){
         cout << el -> second << endl;
      }else{
         cout << "C?" << endl;
      }
   }
   return 0;
}