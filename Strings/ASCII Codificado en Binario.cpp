// https://omegaup.com/arena/problem/ASCII-Codificado-en-Binario/
#include <bits/stdc++.h>

using namespace std;

int procesarCadena(string &cadena){
   int numero = 0;
   int potencia = 0;
   for(int i = cadena.size() - 1; i >= 0; --i){
      if(cadena[i] == '1'){
         numero += pow(2,potencia);
      }
      potencia++;
   }
   return numero;
}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   string cadena;
   while(cin>>cadena){
      cout << char(procesarCadena(cadena));
   }
   return 0;
}