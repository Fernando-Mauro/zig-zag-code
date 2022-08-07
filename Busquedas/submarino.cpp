// https://omegaup.com/arena/problem/OIEG2013SSB
#include <bits/stdc++.h>

using namespace std;

void BFS(){

}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n, m, tiempoMaximo;
   cin >> n >> m >> tiempoMaximo;
   vector <vector <bool>> conexiones(n + 1, vector <bool> (n + 1, false));
   int salida = n;
   int a,b;
   while(m--){
      cin >> a >> b;
      conexiones[a][b] = true;
      conexiones[b][a] = true;
   }
   queue <int> cola;
   cola.push(salida);
   set <int> visitados;
   visitados.insert(salida);
   int tiempoActual = 0, marineros = 0;
   while(!cola.empty() && tiempoActual <( tiempoMaximo - 1)){
      int contador = 0;
      int maximo = cola.size();
      while(contador < maximo){
         int nodo = cola.front();
         cola.pop();
         // marcarlo como visitado
         visitados.insert(nodo);
         // agregar vecinos del nodo a la cola
         for(int i = 0; i < n; ++i){
            if(conexiones[nodo][i] && visitados.find(i) == visitados.end()){
               visitados.insert(i);
               cola.push(i);
               marineros++;
            }
         }
         contador++;
      }
      tiempoActual++;
   }
   cout << marineros << endl;
   return 0;
}