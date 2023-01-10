// https://omegaup.com/arena/problem/CR-Buscando-repeticiones/
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   string buscar, original;
   cin >> buscar;
   string palabra;
   original = buscar;
   transform(buscar.begin(), buscar.end(), buscar.begin(), ::tolower);
   string frase;
   cin.ignore();
   getline(cin, frase);
   int contador = 0;
   for(int i = 0; i < frase.size(); ++i){
      string aux;
      while(frase[i] >= 65 && frase[i] <= 122){
         aux.push_back(frase[i]);
         ++i;
      }
      if(aux == buscar) contador++;
   }
   (contador == 1) ? cout << original << " se repite 1 vez" : cout << original << " se repite "  << contador << " veces";
   return 0;
}