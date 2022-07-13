// https://omegaup.com/arena/problem/El-problema-de-3n1
#include <bits/stdc++.h>

using namespace std;

// key = el numero a buscar
// value = a el numero de pasos para reducir ese numero
map <int, int> resultados;
int reducir(int numero, int pasos){
   if(numero == 1){
      return pasos + 1;
   }
   auto buscar = resultados.find(numero);
   if(buscar != resultados.end()){
      return buscar -> second + pasos;
   }else{
      if(numero % 2 == 0){
         int recursion = reducir(numero / 2, ++pasos);
         resultados.insert({numero, recursion});
         return recursion;
      }else{
         int recursion =  reducir((numero * 3) + 1, ++pasos);
         resultados.insert({numero, recursion});
         return recursion;
      }
   }
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int inicio, fin;
   int mayor = -1;
   cin >> inicio >> fin;
   for(int i = inicio; i <= fin; ++i){ 
      int aux = reducir(i, 0);
      if(aux > mayor){
         mayor = aux;
      }
   }
   cout << mayor - 1;
   return 0;
}