#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int operaciones = 0;
   cin >> operaciones;
   queue <int> clientes;
   int tacosVendidos = 0;
   while(operaciones--){
      int aux;
      cin >> aux;
      switch(aux){
         case 1: int tacos; cin >> tacos; clientes.push(tacos); break;
         case 2: if(!clientes.empty()){
            tacosVendidos += clientes.front();
            clientes.pop();
         } break;
         case 3: cout << clientes.size() << endl;break;
         case 4: cout << tacosVendidos << endl ; break;
      }
   }
   return 0;
}