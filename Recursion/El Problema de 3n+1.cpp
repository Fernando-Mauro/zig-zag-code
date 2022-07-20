// https://omegaup.com/arena/problem/El-problema-de-3n1
#include <bits/stdc++.h>

using namespace std;

// key = el numero a buscar
// value = a el numero de pasos para reducir ese numero
// map <int, int> resultados;
// int reducir(int numero, int pasos){
//    if(numero == 1){
//       return pasos + 1;
//    }
//    auto buscar = resultados.find(numero);
//    if(buscar != resultados.end()){
//       return buscar -> second + pasos;
//    }else{
//       if(numero % 2 == 0){
//          int recursion = reducir(numero / 2, ++pasos);
//          resultados.insert({numero, recursion});
//          return recursion;
//       }else{
//          int recursion =  reducir((numero * 3) + 1, ++pasos);
//          resultados.insert({numero, recursion});
//          return recursion;
//       }
//    }
// }
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int inicio, fin;
   int mayor = -1;
   cin >> inicio >> fin;
   int maximoElementoSecuencia;
   for(int i = inicio; i <= fin; ++i){ 
      int aux = i;
      int pasos = 1;
      cout << "---------------" << endl;
      cout << "Numero:" << i << endl;
      while(aux != 1){
         if(aux % 2 == 0){
            aux /= 2;
            ++pasos;
         }else{
            aux *= 3;
            ++aux;
            ++pasos;
         }
         cout << aux << " ";
      }
      cout << endl;
      cout << "---------------" << endl;
      if (pasos > mayor){
         mayor = pasos;
      }
   }
   cout << mayor;
   return 0;
}