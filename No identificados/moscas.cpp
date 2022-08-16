#include <bits/stdc++.h>

using namespace std;

struct rangos{
   int inicio;
   int final;
};

void vaciarCola(queue <rangos> &maximos){
   while(!maximos.empty()){
      maximos.pop();
   }
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n;
   // arreglo con el numero maximo de tiempo de vida de las moscas
   vector <int> moscas(60000);
   cin >> n;
   int inicio, final;
   int maximo = INT_MIN;
   while(n--){
      cin >> inicio >> final;
      for(; inicio <= final; ++inicio){
         moscas[inicio]++;
         maximo = max(moscas[inicio], maximo);
      }
   }
   int inicioIntervalo = 0;
   int finalIntervalo = 0;
   queue <pair<int,int>> rangos;
   for(int i = 0; i < 60000; ++i){ 
      if(moscas[i] == maximo){
         inicioIntervalo = i;
         finalIntervalo= 1;
         i++;
         while(moscas[i] == maximo){
            finalIntervalo++;
            ++i;
         }
         if(finalIntervalo != 1){
            i -= 1;
            rangos.push({inicioIntervalo, i});
         }
      }
      // cout << moscas[i] << " ";
   }
   cout << rangos.size() << endl;
   while(!rangos.empty()){
      cout << rangos.front().first << " " << rangos.front().second << endl;
      rangos.pop();
   }
   return 0;
}