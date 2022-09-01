// https://omegaup.com/arena/problem/Blancas-Vs-Negras
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n, m, reyNegro, reyBlanco;
   cin >> n >> m;
   set <int> numeros;
   int total  =  n * m;
   int aux;
   int blancas = 0, negras = 0;
   bool whiteKing = false, blacKing = false;
    while(total--){
      cin >> aux;
      if(aux % 2 == 0) negras++;
      else blancas++;
      numeros.insert(aux);
   }
   cout <<  negras << " " <<  blancas << endl;
   int numeroRey, numeroReySegundo;
   cin >> numeroRey >> numeroReySegundo;
   if(numeros.find(numeroRey) != numeros.end() && numeros.find(numeroReySegundo) != numeros.end()){
      cout << "NO JAQUE" << endl;
   }else{
      cout << "JAQUE MATE" << endl;
   }
   return 0;
}