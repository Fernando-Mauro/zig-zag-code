#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int inicio, fin;
   int mayor = -1;
   cin >> inicio >> fin;
   set <int> secuencia;
   for(int i = inicio; i <= fin; ++i){ 
      int aux = i;
      int pasos = 1;
      while(aux != 1){
         if(aux % 2 == 0){
            auto el = secuencia.find(aux);
            if(el != secuencia.end()){
               pasos += secuencia.size(); 
               break;
            }else{
               secuencia.insert(aux);  
            }
            aux /= 2;
            ++pasos;
         }else{
            auto el = secuencia.find(aux);
            if(el != secuencia.end()){
               pasos += secuencia.size(); 
               break;
            }else{
               secuencia.insert(aux);  
            }
            aux *= 3;
            ++aux;
            ++pasos;
         }
      }
      if(pasos > mayor){
            mayor = pasos;
      }
   }
   for(auto it:secuencia){
      cout << it << " ";
   }
   cout << endl <<  mayor << endl;
   return 0;
}